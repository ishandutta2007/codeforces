#include <bits/stdc++.h>

using pii = std::pair<int,int>;
const int maxn = 3e6 + 222;
int n,d,p,a,h[maxn],s[maxn],f[maxn],lim[maxn],tl,c,max[maxn<<2],tag[maxn<<2];
std::vector<pii>v;
void upd(int rt) { max[rt] = std::max(max[rt<<1],max[rt<<1|1]); }
void inc(int rt,int v) { tag[rt] += v, max[rt] += v; }
void pushdown(int rt) {
	inc(rt<<1,tag[rt]);
	inc(rt<<1|1,tag[rt]);
	tag[rt] = 0;
}
int query(int l,int r,int L,int R,int rt) {
	if (l > R || r < L) return 0;
	if (l <= L && R <= r) return max[rt];
	pushdown(rt);
	return std::max(query(l,r,L,(L+R)>>1,rt<<1),query(l,r,((L+R)>>1)+1,R,rt<<1|1));
}
void modify(int p,int v,int l,int r,int rt) {
	if (l == r) { max[rt] = std::max(max[rt],v); return ; }
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (p <= mid) modify(p,v,l,mid,rt<<1);
	else modify(p,v,mid+1,r,rt<<1|1);
	upd(rt);
}

void add(int l,int r,int L,int R,int v,int rt) {
	if (l > R || r < L) return ;
	if (l <= L && R <= r) { inc(rt,v); return ; }
	pushdown(rt);
	add(l,r,L,(L+R)>>1,v,rt<<1);
	add(l,r,((L+R)>>1)+1,R,v,rt<<1|1);
	upd(rt);
}

int main() {
	scanf("%d%d",&n,&d);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d",&p,&a);
		if (p < d) continue;
		h[++tl] = p; h[++tl] = a;
		v.push_back({p,a});
	}
	std::sort(h + 1,h + tl + 1);
	tl = std::unique(h + 1,h + tl + 1) - (h + 1);
	std::sort(v.begin(),v.end(),[](pii x,pii y) { return x.first + x.second < y.first + y.second; });
	for (auto pr:v) {
		int x = pr.first, y = pr.second;
		s[++c] = std::lower_bound(h + 1,h + tl + 1,x) - (h + 1) + 1;
		lim[c] = std::lower_bound(h + 1,h + tl + 1,y) - (h + 1) + 1;
	//	printf("+ <%d %d>\n",s[c],lim[c]);
	} int ans = 0, n = tl;
	for (int i = 1; i <= c; ++ i) {
		if (lim[i] >= s[i]) {
			int v = query(1,s[i],1,n,1);
			modify(lim[i],v + 1,1,n,1);
		} else {
			int v = query(1,lim[i],1,n,1);
			modify(lim[i],v + 1,1,n,1);
			add(lim[i] + 1,s[i],1,n,1,1);
		}
	}
	printf("%d",query(1,n,1,n,1));
	return 0;
}