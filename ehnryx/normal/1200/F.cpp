#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// DON'T USE THESE MACROS DURING ICPC PRACTICE
#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e3+1;
const int M = 10;
const int LCM = 2520;
int val[N], m[N];
int adj[N][M];
int vis[N][LCM];
int ans[N][LCM];

void dfs(int u, int k) {
	vector<pii> path;
	while (!vis[u][k]) {
		vis[u][k] = 2;
		path.push_back(pii(u,k));
		k = ((k+val[u])%LCM + LCM) % LCM;
		u = adj[u][k%m[u]];
	}
	if (vis[u][k] == 1) {
		for (const pii& it : path) {
			ans[it.first][it.second] = ans[u][k];
			vis[it.first][it.second] = 1;
		}
	} else {
		unordered_set<int> cur;
		cur.insert(u);
		for (int i=path.size()-1; path[i]!=pii(u,k); i--) {
			cur.insert(path[i].first);
		}
		for (const pii& it : path) {
			ans[it.first][it.second] = cur.size();
			vis[it.first][it.second] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n;
	cin >> n;

	FOR(i,1,n) {
		cin >> val[i];
	}

	FOR(i,1,n) {
		cin >> m[i];
		For(j,m[i]) {
			cin >> adj[i][j];
		}
	}

	FOR(i,1,n) {
		For(k,LCM) {
			if (!vis[i][k]) {
				dfs(i,k);
			}
		}
	}

	int q;
	cin >> q;
	For(i,q) {
		int x, y;
		cin >> x >> y;
		y = (y%LCM + LCM) % LCM;
		cout << ans[x][y] << nl;
	}

	return 0;
}