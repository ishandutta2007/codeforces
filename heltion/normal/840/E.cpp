#include<bits/stdc++.h>
using namespace std;
using US = unsigned short;
constexpr int maxm = 8;
constexpr int maxn = 54000;
US a[maxn], q[maxn], p[maxn], fp[maxn], d[maxn];
vector<US> G[maxn];
struct trie{
	US c[2][1 << (maxm + 1)], cnt = 1;
	US ans[1 << maxm];
	void insert(US mask, US v){
		US p = 1;
		for(US i = 1; i <= maxm; i += 1){
			US t = (mask >> (maxm - i)) & 1;
			if(not c[t][p]) c[t][p] = cnt += 1;
			p = c[t][p];
		}
		c[0][p] = max(c[0][p], v);
	}
	US find(US mask){
		if(cnt == 1) return 0;
		US p = 1, res = 0;
		for(US i = 1, d; i <= maxm; i += 1, p = c[d][p]){
			US t = (mask >> (maxm - i)) & 1;
			if(not c[0][p]) d = 1;
			else if(not c[1][p]) d = 0;
			else d = t ^ 1;
			res = (res << 1) + (d ^ t);
		}
		return (res << maxm) + c[0][p];
	}
}t[maxn];
void DFS(US u){
	d[u] = d[p[u]] + 1;
	for(US v : G[u]) if(v != p[u]){
		p[v] = u;
		DFS(v);
	}
}
void pre(US u){
	for(US i = 0, x = u; x and i < (1 << maxm); i += 1, fp[u] = x = p[x])
		t[u].insert(a[x] >> maxm, (a[x] & ((1 << maxm) - 1)) ^ i);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	US n;
	int q;
	cin >> n >> q;
	for(US i = 1; i <= n; i += 1) cin >> a[i];
	for(US i = 1, u, v; i < n; i += 1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1);
	for(US i = 1; i <= n; i += 1){
		pre(i);
		for(US j = 0; j < (1 << maxm); j += 1) t[i].ans[j] = t[i].find(j);
	}
	for(US u, v; q; q -= 1){
		cin >> u >> v;
		US dis = 0, ans = 0;
		for(; d[fp[v]] + 1 >= d[u] and v; v = fp[v], dis += (1 << maxm))
			ans = max(ans, t[v].ans[dis >> maxm]);
		for(; d[v] >= d[u]; v = p[v], dis += 1)
			ans = max(ans, (US)(a[v] ^ dis));
		cout << ans << "\n";
	}
	return 0;
}