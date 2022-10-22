#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
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

const int N = 5e5+2;
int val[N], ans[N];
vector<int> adj[N];

void solve(int u, int& v) {
	ans[u] = v++;
	for (int x : adj[u]) {
		solve(x, v);
	}
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

	int T;
	cin >> T;
	while (T--) {

		int n;
		cin >> n;

		for (int i=1; i<=n+1; i++) {
			adj[i].clear();
		}

		for (int i=1; i<=n; i++) {
			cin >> val[i];
			if (val[i] == -1) val[i] = i+1;
			adj[val[i]].push_back(i);
		}

		solve(n+1, *(new int(-1)));

		vector<pii> p;
		for (int i=1; i<=n+1; i++) {
			ans[i] = n-ans[i];
			p.push_back(pii(ans[i],i));
		}
		sort(p.begin(), p.end(), greater<pii>());

		set<int> idx;
		for (const pii& it : p) {
			if (!idx.empty()) {
				if (val[it.second] != *idx.upper_bound(it.second)) {
					goto bad;
				}
			}
			idx.insert(it.second);
		}

		for (int i=1; i<=n; i++) {
			cout << ans[i] << " ";
		}
		cout << nl;
		continue;

		bad:
		cout << -1 << nl;
		continue;

	}

	return 0;
}