#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
vi eg[maxn], be[maxn];
int sz[maxn];
int dis[maxn];
int k;
int p[maxn];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v), be[v].pb(u);
	}
	cin >> k;
	for (int i = 1; i <= k; i++)
		scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++)
		dis[i] = 10 * maxn;
	dis[p[k]] = 0;
	queue<int> s;
	s.push(p[k]);
	while (!s.empty()) {
		int fr = s.front(); s.pop(); 
		for (auto v : be[fr]) 
			if (dis[v] > dis[fr] + 1) {
				dis[v] = dis[fr] + 1;
				s.push(v);
			}
	}
	for (int i = 1; i <= n; i++)
		for (auto v : eg[i])
			if (dis[v] == dis[i] - 1)
				sz[i]++;
	int mn = 0, mx = 0;
	for (int i = 2; i <= k; i++) {
		if (dis[p[i]] != dis[p[i - 1]] - 1) mn++, mx++;
		else if (sz[p[i - 1]] >= 2) mx++;
	}
	cout << mn << ' ' << mx << endl;
	return 0;
}