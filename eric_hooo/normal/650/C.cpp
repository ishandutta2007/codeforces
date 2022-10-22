#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

vector <vector <int> > a;
vector <pii> all[1000010];
vector <int> from[1000010];
int dp[1000010], in[1000010];
int n, m;

int key(int x, int y){return x * m + y;}
int key(pii x){return x.fi * m + x.se;}

queue <int> q;

int fa[1000010];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main(){
	scanf("%d%d", &n, &m);
	a.resize(n);
	for (int i = 0; i < n; i++){
		a[i].resize(m);
		for (int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			fa[key(i, j)] = key(i, j);
		}
	}
	for (int i = 0; i < n; i++){
		vector <pii> v;
		for (int j = 0; j < m; j++){
			v.push_back(mp(a[i][j], key(i, j)));
		}
		sort(v.begin(), v.end());
		for (int j = 1; j < m; j++){
//			cout << "   v[j].fi:" << v[j].fi << endl;
//			cout << "   v[j - 1].fi:" << v[j - 1].fi << endl;
//			cout << "   pd:" << (v[j].fi == v[j - 1].fi) << endl;
			if (v[j].fi == v[j - 1].fi) fa[find(v[j].se)] = find(v[j - 1].se);
		}
	}
	for (int j = 0; j < m; j++){
		vector <pii> v;
		for (int i = 0; i < n; i++){
			v.push_back(mp(a[i][j], key(i, j)));
		}
		sort(v.begin(), v.end());
		for (int i = 1; i < n; i++){
			if (v[i].fi == v[i - 1].fi) fa[find(v[i].se)] = find(v[i - 1].se);
		}
	}
	for (int i = 0; i < n; i++){
		vector <pii> v;
		for (int j = 0; j < m; j++){
			v.push_back(mp(a[i][j], key(i, j)));
		}
		sort(v.begin(), v.end());
		for (int j = 1; j < m; j++){
			if (find(v[j - 1].se) != find(v[j].se)){
				from[find(v[j - 1].se)].push_back(find(v[j].se));
				in[find(v[j].se)]++;
			}
		}
	}
	for (int j = 0; j < m; j++){
		vector <pii> v;
		for (int i = 0; i < n; i++){
			v.push_back(mp(a[i][j], key(i, j)));
		}
		sort(v.begin(), v.end());
		for (int i = 1; i < n; i++){
			if (find(v[i - 1].se) != find(v[i].se)){
				from[find(v[i - 1].se)].push_back(find(v[i].se));
				in[find(v[i].se)]++;
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (!in[find(key(i, j))] && dp[find(key(i, j))] != 1){
				dp[find(key(i, j))] = 1, q.push(find(key(i, j)));
			}
		}
	}
	int ans = 1;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int i = 0; i < from[u].size(); i++){
			int v = from[u][i];
			in[v]--, dp[v] = max(dp[v], dp[u] + 1);
			ans = max(ans, dp[v]);
			if (!in[v]) q.push(v);
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf("%d ", dp[find(key(i, j))]);
		}
		printf("\n");
	}
	return 0;
}