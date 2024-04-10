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

const int N = 3e5+1;
const int L = 19;
int a[N];
int dp[N][L];

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, q;
	cin >> n >> q;

	FOR(i,1,n) {
		cin >> a[i];
	}

	vector<int> memo[L];
	FOR(i,1,n) {
		For(j,L) {
			if (a[i]&1<<j) {
				dp[i][j] = i;
				if (!memo[j].empty()) {
					For(k,L) {
						dp[i][k] = max(dp[i][k], dp[memo[j].back()][k]);
					}
				}
				memo[j].push_back(i);
			}
		}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		bool ok = false;
		For(j,L) {
			ok |= ((a[x]&1<<j) && dp[y][j] >= x);
		}
		if (ok) cout << "Shi" << nl;
		else cout << "Fou" << nl;
	}

	return 0;
}