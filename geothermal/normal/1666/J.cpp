#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define trav(a, v) for (auto &a : v)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

const char nl = '\n';

int bst[201][201];
int ans[201];
int N;
void go(int x, int y, int p) {
	if (x > y || y < 0 || x >= N) return;
	if (x == y) {
		ans[x] = p; return;
	}
	ans[bst[x][y]] = p;
	go(x, bst[x][y] - 1, bst[x][y]);
	go(bst[x][y] + 1, y, bst[x][y]);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N;
	ll C[N][N]; F0R(i, N) F0R(j, N) cin >> C[i][j];
	ll cp[N][N+1];
	F0R(i, N) {
		cp[i][0] = 0;
		F0R(j, N) {
			cp[i][j+1] = cp[i][j] + C[i][j];
		}
	}

	ll dp[N][N];
	ll nc[N][N];
	F0R(i, N) dp[i][i] = 0;
	F0R(i, N) {
		FOR(j, i, N) {
			nc[i][j] = 0;
			FOR(k, i, j+1) {
				nc[i][j] += cp[k][i] + cp[k][N] - cp[k][j+1];
			}
		}
	}

	FOR(l, 1, N) {
		F0R(i, N) {
			int j = i+l;
			if (j >= N) continue;
			dp[i][j] = 1e18;
			FOR(k, i, j+1) {
				ll cur = 0;
				if (k > i) {
					cur += dp[i][k-1] + nc[i][k-1];
				}
				if (k < j) {
					cur += dp[k+1][j] + nc[k+1][j];
				}
				if (dp[i][j] > cur) {
					dp[i][j] = cur; 
					bst[i][j] = k;
				}
			}
		}
	}
	go(0, N-1, -1);
	F0R(i, N) {
		cout << ans[i] + 1 << " ";
	}
	cout << nl;
}