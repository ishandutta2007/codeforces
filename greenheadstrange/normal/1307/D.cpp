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
int dis[maxn], q[maxn];
int c[maxn][2];
vi eg[maxn];
void gd(int a) {
	int fr = 0, ed = 0;
	memset(dis, -1, sizeof(dis));
	dis[a] = 0, q[ed++] = a;
	while (fr < ed) {
		int f = q[fr]; fr++;
		for (auto v : eg[f]) {
			if (dis[v] != -1) continue;
			dis[v] = dis[f] + 1, q[ed++] = v;
		}
	}
}
int a[maxn];
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v), eg[v].pb(u);
	}
	gd(1); for (int i = 1; i <= n; i++) c[i][0] = dis[i];
	gd(n); for (int i = 1; i <= n; i++) c[i][1] = dis[i];
	int ff = dis[1];
	vector<pi> cur;
	for (int i = 1; i <= k; i++)
		cur.pb(mp(c[a[i]][0] - c[a[i]][1], a[i]));
	sort(cur.begin(), cur.end());
	int uu = 0, mx = 0;
//	cout << ff << ' ' << uu << endl; 
	for (int i = 0; i < cur.size(); i++) {
		int id = cur[i].se;
	//	cout << c[id][0] << ' ' << c[id][1] << endl;
		if (i) uu = max(uu, mx + 1 + c[id][1]);
		mx = max(mx, c[id][0]);
	}
	cout << min(ff, uu) << endl;
	return 0;
}