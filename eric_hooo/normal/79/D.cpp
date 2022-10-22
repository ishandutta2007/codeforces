#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

int a[10010];
int dist[30][30];
int vis[10010], ways[110];
queue <pii> q;
int n, k, l;

void bfs(int s){
//	cout << s << " " << e << endl;
	memset(vis, -1, sizeof(vis));
	while (!q.empty()) q.pop();
	vis[s] = 0;
	q.push(mp(s, 0));
	while (!q.empty()){
		pii t = q.front(); q.pop();
//		cout << "  " << t.fi << endl;
		int u = t.fi, dist = t.se + 1;
		for (int i = 0; i < l; i++){
			int v = u + ways[i];
			if (v <= n + 1 && vis[v] == -1) vis[v] = dist, q.push(mp(v, dist));
			v = u - ways[i];
			if (v > 0 && vis[v] == -1) vis[v] = dist, q.push(mp(v, dist));
		}
	}
}

vector <int> v[30];

int Count(int x){
	int res = 0;
	while (x){
		res += x & 1;
		x >>= 1;
	}
	return res;
}

int dp[2097162];

int main(){
	scanf("%d%d%d", &n, &k, &l);
	for (int i = 0; i < k; i++){
		int t; scanf("%d", &t);
		a[t] = 1;
	}
	for (int i = 0; i < l; i++){
		scanf("%d", &ways[i]);
	}
	vector <int> all;
	for (int i = 1; i <= n + 1; i++){
		if (a[i] != a[i - 1]) all.push_back(i);
	}
	for (int i = 0; i < all.size(); i++){
		bfs(all[i]);
		for (int j = i + 1; j < all.size(); j++){
			dist[i][j] = dist[j][i] = vis[all[j]];
		}
	}
	for (int p = 0; p < (1 << all.size()); p++){
		int t = Count(p);
		if (!(t & 1)) v[t].push_back(p);
	}
	memset(dp, INF, sizeof(dp));
	dp[0] = 0;
	for (int x = 2; x <= all.size(); x += 2){
		for (int y = 0; y < v[x].size(); y++){
			int p = v[x][y];
			for (int i = 0; i < all.size(); i++){
				if (!(p & (1 << i))) continue;
				for (int j = i + 1; j < all.size(); j++){
					if (!(p & (1 << j)) || dist[i][j] == -1) continue;
					int n_p = p ^ (1 << i) ^ (1 << j);
					dp[p] = min(dp[p], dp[n_p] + dist[i][j]);
				}
			}
		}
	}
	int end = (1 << all.size()) - 1;
	printf("%d\n", dp[end] == INF ? -1 : dp[end]);
	return 0;
}