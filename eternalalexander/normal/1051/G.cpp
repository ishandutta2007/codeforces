#include <bits/stdc++.h>

using ll = long long;
const int maxn = 4e5 + 17;

int ch[maxn << 5][2], n, vis[maxn], rt[maxn], tl, a[maxn], b[maxn], l[maxn], r[maxn];
ll cost[maxn], sum[maxn << 5], cnt[maxn << 5], ans, move[maxn];
std::stack<int>stk;
std::vector<int>G[maxn];

int nxt[maxn];

int find_next(int x) {
	return nxt[x] ? nxt[x] = find_next(nxt[x]) : x;
}

int newnode() {
	if (!stk.empty()) { int u = stk.top(); stk.pop(); return u; }
	return ++tl;
}

int insert(int rt,int l,int r,int p) {
	if (!rt) rt = newnode();
	sum[rt] += p;
	cnt[rt] ++;
	if (l == r) return rt;
	int mid = (l + r) >> 1;
	if (p <= mid) ch[rt][0] = insert(ch[rt][0],l,mid,p);
	else ch[rt][1] = insert(ch[rt][1],mid+1,r,p);
	return rt;
}

ll query_cnt(int rt,int l,int r,int L,int R) {
	if (l > R || r < L || l > r) return 0;
	if (l <= L && R <= r) return cnt[rt];
	return query_cnt(ch[rt][0],l,r,L,(L+R)>>1) + query_cnt(ch[rt][1],l,r,((L+R)>>1)+1,R);
}

ll query_sum(int rt,int l,int r,int L,int R) {
	if (l > R || r < L || l > r) return 0;
	if (l <= L && R <= r) return sum[rt];
	return query_sum(ch[rt][0],l,r,L,(L+R)>>1) + query_sum(ch[rt][1],l,r,((L+R)>>1)+1,R);
}

void destroy(int x) {
	if (!x) return;
	if (ch[x][0]) destroy(ch[x][0]);
	if (ch[x][1]) destroy(ch[x][1]);
	stk.push(x);
	ch[x][0] = ch[x][1] = sum[x] = cnt[x] = 0;
}

void merge(int u,int v) {
	if (G[u].size() < G[v].size()) std::swap(u,v);
	
	int a1 = (l[u] < l[v] ? u : v); int b1 = u ^ v ^ a1;
	ans -= cost[v]; ans -= cost[u];
	ans -= move[v]; ans -= move[u];
	move[u] += move[v];
	ll sumb = sum[rt[b1]];
	move[u] -= sumb * (l[b1] - l[a1]);
	for (auto x:G[v]) {
		ll suf = query_cnt(rt[u],b[x] + 1,n,1,n);
		ll pre = query_sum(rt[u],1,b[x],1,n);
		cost[u] += pre + suf * b[x];
		rt[u] = insert(rt[u],1,n,b[x]);
		vis[a[x]] = u;
		G[u].push_back(x);
	} ans += cost[u] + move[u];
	G[v].clear();
	destroy(rt[v]);
	l[u] = std::min(l[u],l[v]);
	r[u] = std::max(r[u],r[v]);
//	printf(">%d %d %d\n",cost[u],move[u],ans);
//	for (int i = 1; i <= n; ++ i) printf("%d ",vis[i]); puts("");
}

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d",&a[i],&b[i]);
		int p = find_next(a[i]);
//		printf("occupie %d\n",p);
		ans += (ll) b[i] * (p - a[i]);
		a[i] = p;
		nxt[a[i]] = a[i] + 1;
		vis[a[i]] = i; 
		l[i] = r[i] = a[i];
		G[i].push_back(i);
		rt[i] = insert(rt[i],1,n,b[i]);
		if (vis[a[i]-1]) merge(vis[a[i]],vis[a[i]-1]);
		if (vis[a[i]+1]) merge(vis[a[i]],vis[a[i]+1]); 
		printf("%lld\n",ans);
	}
	return 0;
}