#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

ll power(ll b, int e) {
	ll res = 1;
	for ( ; e>0; e/=2) {
		if (e&1) res = res*b % MOD;
		b = b*b % MOD;
	}
	return res;
}

ll inv(ll n) {
	return power(n, MOD-2);
}

const int N = 2e5+1;
vector<int> adj[N];
int p[N], c[N];
ll f[N], g1[N], g2[N];

ll solvef(int);
ll solveg1(int);
ll solveg2(int);

ll solvef(int u) {
	if (f[u] != -1) return f[u];
	f[u] = 1;
	for (int x : adj[u]) {
		f[u] = f[u] * (solvef(x)+solveg2(x)) % MOD;
	}
	return f[u];
}

ll solveg1(int u) {
	if (g1[u] != -1) return g1[u];
	if (!c[u]) return g1[u] = 1;
	ll res = 0;
	for (int x : adj[u]) {
		res += solvef(u) * inv(solvef(x)+solveg2(x)) % MOD * (solveg1(x)+solveg2(x)) % MOD;
	}
	return g1[u] = res % MOD;
}

ll solveg2(int u) {
	if (g2[u] != -1) return g2[u];
	if (!c[u]) return g2[u] = 0;
	ll tot = 1;
	for (int x : adj[u]) {
		tot = tot * ((solvef(x)+solveg2(x) + solveg1(x)+solveg2(x)) % MOD) % MOD;
	}
	return g2[u] = (tot-solvef(u)-solveg1(u)) % MOD;
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	memset(f, -1, sizeof f);
	memset(g1, -1, sizeof g1);
	memset(g2, -1, sizeof g2);

	int n;
	cin >> n;

	for (int i=2; i<=n; i++) {
		cin >> p[i];
		adj[p[i]].push_back(i);
		c[p[i]]++;
	}
	ll ans = solvef(1) + solveg2(1);
	cout << (ans%MOD + MOD) % MOD << nl;

#ifdef DEBUG
	for (int i=1; i<=n; i++) {
		cerr << nl << "Node " << i << nl;
		cerr << "  f  " << solvef(i) << nl;
		cerr << "  g1 " << solveg1(i) << nl;
		cerr << "  g2 " << solveg2(i) << nl;
	}
#endif

	return 0;
}