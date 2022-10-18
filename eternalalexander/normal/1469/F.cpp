#include <bits/stdc++.h>

#define maxn 2000005
const int lim = 1e6;
using ll = long long;

int n,d[maxn],tl=1,ans=1e9,len[maxn];
ll l[maxn],k;

int newnode() { return ++tl; }

struct segmentTree {
	ll sum[maxn<<2],tag[maxn<<2];
	void reset() { std::memset(sum,0,sizeof(sum)); std::memset(tag,0,sizeof(tag)); }
	void give_tag(ll v,int rt,int l,int r) {
		tag[rt] += v;
		sum[rt] += v * (ll) (r - l + 1);
	} void update(int rt) { sum[rt] = sum[rt<<1] + sum[rt<<1|1]; }
	void pushdown(int rt,int l,int r) {
		int mid = (l + r) >> 1;
		give_tag(tag[rt],rt<<1,l,mid);
		give_tag(tag[rt],rt<<1|1,mid+1,r);
		tag[rt] = 0;
	}
	void add(int l,int r,int L,int R,ll v,int rt) {
		if (l > R || r < L) return;
		if (l <= L && R <= r) { give_tag(v,rt,L,R); return; }
		pushdown(rt,L,R);
		add(l,r,L,(L+R)>>1,v,rt<<1);
		add(l,r,((L+R)>>1)+1,R,v,rt<<1|1);
		update(rt);
	} ll query(int l,int r,int L,int R,int rt) {
		if (l>R||r<L) return 0;
		if (l <= L && R <= r) return sum[rt];
		pushdown(rt,L,R);
		return query(l,r,L,(L+R)>>1,rt<<1) + query(l,r,((L+R)>>1)+1,R,rt<<1|1);
	}
}seg;

int answer() {
	int l = 0, r = lim, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (seg.query(0,mid,0,lim,1) >= k) { ans = mid; r = mid - 1; }
		else l = mid + 1;
	} return ans;
}

int main() {
	scanf("%d%lld",&n,&k);
	assert(k >= 2);
	for (int i = 1; i <= n; ++ i) 
		scanf("%lld",&l[i]);
//if (std::accumulate(l+1,l+n+1,0ll) + 1 - 2 * n < k) { puts("-1"); return 0; }
	std::sort(l+1,l+n+1,[](ll a,ll b) { return a > b; });
	std::priority_queue<std::pair<int,int> >q;
	seg.reset();
	seg.add(0,0,0,lim,1,1);
	//puts("!");
	q.push({0,1}); len[1] = 1;
	for (int i = 1; i <= n; ++ i) {
		auto P = q.top(); q.pop();
		int u = P.second;
	//	puts("!");
		seg.add(d[u],d[u],0,lim,-1,1); len[u] --;
		if (len[u] > 0) {
			int x = newnode();
			len[x] = len[u];
			d[x] = d[u] + 1;
			q.push({-d[x],x});
		}
		int a = newnode(), b = newnode(), c = newnode();
	//	printf("%d -> %d = %d %d\n",u,a,b,c);
		d[a] = d[u] + 1; d[b] = d[c] = d[a] + 1;
		q.push({-d[b],b}); q.push({-d[c],c});
		int L = l[i] / 2, R = (l[i] - 1) / 2;
		len[b] = L; len[c] = R;
	//	printf("[%d %d] [%d %d]\n",d[a] + 1, d[a] + L, d[a] + 1, d[a] + R);
		seg.add(d[a] + 1, d[a] + L, 0, lim, 1, 1);
		seg.add(d[a] + 1, d[a] + R, 0, lim, 1, 1); 
		if (seg.sum[1] >= k) ans = std::min(ans,answer());
	}// assert(ans <= lim);
	printf("%d",ans <= lim ? ans : -1);
	return 0;
}