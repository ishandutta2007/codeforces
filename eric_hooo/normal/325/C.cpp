#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 314000000;

vector <int> query[100010];
vector <int> all[100010];
int id[100010];
int cnt[100010];
int val[100010];
int dist[100010];
int m, n;
priority_queue <pii, vector <pii>, greater <pii> > q;
vector <int> from[100010];

void Dij(int s){
	for (int i = 0; i <= n; i++){
		dist[i] = 0x3f3f3f3f;
	}
	dist[s] = 0, q.push(mp(dist[s], s));
	while (!q.empty()){
		pii t = q.top(); q.pop();
		int x = t.se;
		if (dist[x] != t.fi) continue;
		for (int i = 0; i < from[x].size(); i++){
			int v = from[x][i];
			cnt[v]--, val[v] = min(INF, val[v] + dist[x]);
			if (!cnt[v]){
				if (dist[id[v]] > val[v]){
					dist[id[v]] = val[v];
					q.push(mp(dist[id[v]], id[v]));
				}
			}
		}
	}
}

pii ans[100010];
int dp[100010];
int last[100010];
int vis[100010];

int dfs(int x){
	if (vis[x]) return -2;
	if (~dp[x]) return dp[x];
	vis[x] = 1;
	for (auto id : query[x]){
		int ndp = last[id];
		for (auto v : all[id]){
			if (dist[v] == 0x3f3f3f3f) goto END3;
		}
		for (auto v : all[id]){
			if (!v) continue;
			if (dfs(v) == -2) return dp[x] = -2;
			ndp = min(INF, ndp + dfs(v));
		}
		dp[x] = max(dp[x], ndp);
		END3:;
	}
	vis[x] = 0;
	return dp[x];
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &id[i], &cnt[i]);
		query[id[i]].push_back(i);
		int l = cnt[i];
		while (l--){
			int x; scanf("%d", &x);
			if (x == -1) val[i]++, cnt[i]--;
			else all[i].push_back(x);
		}
		last[i] = val[i];
		if (!all[i].size()) all[i].push_back(0), cnt[i]++;
		for (auto x : all[i]){
			from[x].push_back(i);
		}
	}
	Dij(0);
	for (int i = 1; i <= n; i++){
		if (dist[i] == 0x3f3f3f3f){
			printf("-1 -1\n");
		} else {
			printf("%d %d\n", dist[i], dfs(i));
		}
	}
	return 0;
}