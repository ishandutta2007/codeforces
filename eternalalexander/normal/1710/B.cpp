#include <bits/stdc++.h>


const int maxn = 1e6 + 222;
using ll = long long;

int n,ans[maxn],rk1[maxn],rk[maxn],tl,t1,l[maxn],r[maxn],m[maxn];
ll p[maxn],x[maxn],y[maxn],d[maxn],lim,h[maxn],cur[maxn];

struct StarlightGlimmer { // SG Tree = Starlight Glimmer Tree
	ll sum[maxn << 2],tag[maxn << 2];
	void update(int rt) { sum[rt] = sum[rt<<1] + sum[rt<<1|1]; }
	void give_tag(int rt,int l,int r,ll v) {
		sum[rt] += (ll) (r - l + 1) * v;
		tag[rt] += v;
	}
	void pushdown(int rt,int l,int r) {
		int mid = (l + r) >> 1;
		give_tag(rt<<1,l,mid,tag[rt]);
		give_tag(rt<<1|1,mid+1,r,tag[rt]);
		tag[rt] = 0;
	}
	void build(int l,int r,int rt) {
		sum[rt] = tag[rt] = 0;
		if (l == r) {
			
			return ;
		} int mid = (l + r) >> 1;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		update(rt);
	} 
	void reset() { build(1,tl,1); }
	void add(int L,int R,int l,int r,ll v,int rt) {
		if (l > R || r < L) return ;
		if (l <= L && R <= r) { give_tag(rt,L,R,v); return; }
		pushdown(rt,L,R);
		add(L,(L+R)>>1,l,r,v,rt<<1);
		add(((L+R)>>1)+1,R,l,r,v,rt<<1|1);
		update(rt);
	}
	ll query(int L,int R,int l,int r,int rt) {
		if (l > R || r < L) return 0;
		if (l <= L && R <= r) return sum[rt];
		pushdown(rt,L,R);
		return query(L,(L+R)>>1,l,r,rt<<1) + query(((L+R)>>1)+1,R,l,r,rt<<1|1);
	}
} S1,S2;

void solve() {
	tl = t1 = 0; 
	scanf("%d%lld",&n,&lim);
	for (int i = 1; i <= n; ++ i) {
		ans[i] = 0; cur[i] = 0; l[i] = r[i] = m[i] = 0;rk1[i] = rk[i] = 0;
		scanf("%lld%lld",&x[i],&p[i]);
		h[++tl] = x[i]; h[++tl] = x[i] + p[i]; h[++tl] = x[i] - p[i];
		rk1[i] = i;
	} std::sort(h + 1, h + tl + 1);
	for (int i = 1; i <= n; ++ i) {
		l[i] = std::lower_bound(h + 1,h + tl + 1,x[i] - p[i]) - (h + 1) + 1;
		m[i] = std::lower_bound(h + 1,h + tl + 1,x[i]) - (h + 1) + 1;
		r[i] = std::lower_bound(h + 1,h + tl + 1,x[i] + p[i]) - (h + 1) + 1;
	}
	// calculate cur
	S1.reset(); S2.reset();
	for (int i = 1; i <= n; ++ i) {
		S1.add(1,tl,m[i],r[i],p[i] + x[i],1);
	//	printf("add [%d %d] %lld\n",m[i],r[i],p[i] + x[i]);
		 S1.add(1,tl,l[i],m[i] - 1,p[i] - x[i],1);
		S2.add(1,tl,m[i],r[i],-1,1); 
		S2.add(1,tl,l[i],m[i]-1,1,1);
	} for (int i = 1; i <= n; ++ i) {
		cur[i] = S1.query(1,tl,m[i],m[i],1) + (ll) x[i] * S2.query(1,tl,m[i],m[i],1);
	//	printf("<%d %d %d> %d %lld\n",l[i],m[i],r[i],i,cur[i]);
		if (cur[i] > lim) {
			ll det = cur[i] - lim;
			y[++t1] = x[i]; d[t1] = det;
			rk[t1] = t1;
		}
	} 
//	printf("t1 = %d\n",t1);
	S1.reset();
	int pt = 0;
	std::sort(rk1 + 1,rk1 + n + 1,[](int a,int b) { return p[a] + x[a] < p[b] + x[b]; });
	std::sort(rk+1,rk+t1+1,[](int a,int b) { return y[a] + d[a] < y[b] + d[b]; });
	for (int i = 1; i <= n; ++ i) {
		int a = rk1[i];
		while (pt < t1 && y[rk[pt+1]] + d[rk[pt+1]] <= p[a] + x[a]) {
			pt ++;
			//printf("+ %lld %lld\n",y[rk[pt]],d[rk[pt]]);
			int p1 = std::lower_bound(h+1,h+tl+1,y[rk[pt]]) - (h+1) + 1;
			S1.add(1,tl,p1,p1,1,1);
		}
		ans[a] += S1.query(1,tl,m[a],tl,1);
		//printf("ans[%d] += %d\n",a,S1.query(1,tl,1,m[a],1));
	} 
	S1.reset();
	pt = 0;
	std::sort(rk1 + 1,rk1 + n + 1,[](int a,int b) { return p[a] - x[a] < p[b] - x[b]; });
	std::sort(rk+1,rk+t1+1,[](int a,int b) { return -y[a] + d[a] < -y[b] + d[b]; });
	for (int i = 1; i <= n; ++ i) {
		int a = rk1[i];
		while (pt < t1 && -y[rk[pt+1]] + d[rk[pt+1]] <= p[a] - x[a]) {
			pt ++;
			int p1 = std::lower_bound(h+1,h+tl+1,y[rk[pt]]) - (h+1) + 1;
			S1.add(1,tl,p1,p1,1,1);
		}
		ans[a] += S1.query(1,tl,1,m[a]-1,1);
		//printf("ans[%d] += %d\n",a,S1.query(1,tl,1,m[a],1));
	} 
	for (int i = 1; i <= n; ++ i) {
	//	printf("%d ",ans[i]);
		printf("%d",ans[i] == t1);
	}
	puts("");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}