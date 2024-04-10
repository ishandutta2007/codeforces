#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <pii> from[1000010], g[1000010];
int id[1000010], low[1000010], ins[1000010], scc[1000010], in[1000010];
long long tot[1000010], dp[1000010];
int cnt = 1, all;
long long sum[100010];
long long sum2[100010];
vector <int> s, order;
queue <int> q;

int read(){
    int x = 0;
    char c = getchar();
    while (c < '0' || c > '9') c = getchar();
    x = c ^ '0', c = getchar();
    while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ '0'), c = getchar();
    return x;
}

void dfs(int x){
	id[x] = low[x] = cnt++;
	s.push_back(x), ins[x] = 1;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i].fi;
		if (!id[v]) dfs(v), low[x] = min(low[x], low[v]);
		else if (ins[v]) low[x] = min(low[x], id[v]);
	}
	if (id[x] != low[x]) return ;
	while (1){
		int v = s.back(); s.pop_back();
		ins[v] = 0, scc[v] = all;
		if (x == v) break;
	}
	all++;
}

int main(){
	for (int i = 1; i <= 20000; i++){
		sum[i] = sum[i - 1] + i;
		sum2[i] = sum2[i - 1] + sum[i];
	}
	int n = read(), m = read();
	for (int i = 0; i < m; i++){
		int u = read(), v = read(), w = read();
		from[u].push_back(mp(v, w));
	}
	for (int i = 1; i <= n; i++){
		if (!id[i]) dfs(i);
	}
	for (int x = 1; x <= n; x++){
		for (int j = 0; j < from[x].size(); j++){
			int v = from[x][j].fi, w = from[x][j].se;
			if (scc[x] == scc[v]){
				int pos = upper_bound(sum, sum + 20000, w) - sum - 1;
//				cout << "  pos" << pos << endl;
				tot[scc[x]] += 1ll * w * (pos + 1) - sum2[pos];
//				cout << "w:" << w << " " << 1ll * w * (pos + 1) - sum2[pos] << endl;
			} else g[scc[x]].push_back(mp(scc[v], w)), in[scc[v]]++;
		}
	}
	for (int i = 0; i < all; i++){
		if (!in[i]) q.push(i);
	}
	while (!q.empty()){
		int x = q.front(); q.pop();
		order.push_back(x);
		for (int i = 0; i < g[x].size(); i++){
			int v = g[x][i].fi;
			in[v]--;
			if (!in[v]) q.push(v);
		}
	}
	reverse(order.begin(), order.end());
//	cout << "order:";
	for (int i = 0; i < order.size(); i++){
		int x = order[i];
//		cout << x << " ";
		for (int j = 0; j < g[x].size(); j++){
			int v = g[x][j].fi, w = g[x][j].se;
			dp[x] = max(dp[x], dp[v] + w);
		}
		dp[x] += tot[x];
	}
	int s = read();
	printf("%I64d\n", dp[scc[s]]);
	return 0;
}