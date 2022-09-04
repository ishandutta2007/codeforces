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

const int MX = 5001;
const int MOD = 998244353;

ll dp[MX][MX];
ll facs[MX];
ll invFacs[MX];

ll modPow(ll N, ll P) {
	if (P == 0) return 1;
	ll K = modPow(N, P/2);
	K *= K; K %= MOD;
	if (P % 2) {
		K *= N; K %= MOD;
	}
	return K;
}

void solve() {
	int N; cin >> N;
	int A[N]; F0R(i, N) A[i] = 0;
	F0R(i, N) {
		int X; cin >> X; X--; A[X]++;
	}
	F0R(i, N+1) {
		F0R(j, N/2 + 1) {
			dp[i][j] = 0;
		}
	}
	int ns = 0;
	dp[N][0] = 1;
	FORd(i, 1, N+1) {
		F0R(j, N/2 + 1) {
			F0R(k, 2) {
				int ext = A[i-1] - k;
				if (ext < 0 || j + k > N/2) continue;
				int allow = j * 2 - 1 - ns;
				if (j == 0 && ns == 0) {
					allow = 0;
				} else if (j == N/2) allow = N - ns;
				if (allow >= ext) {
					ll val = dp[i][j];
					val *= facs[allow]; val %= MOD;
					val *= invFacs[allow-ext]; val %= MOD;
					val *= invFacs[ext]; val %= MOD;
					dp[i-1][j+k] += val;
					dp[i-1][j+k] %= MOD;
				}
			}
		}
		ns += A[i-1];
	}

	cout << dp[0][N/2] << nl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	facs[0] = 1;
	FOR(i, 1, MX) {
		facs[i] = facs[i-1] * i;
		facs[i] %= MOD;
	}
	F0R(i, MX) {
		invFacs[i] = modPow(facs[i], MOD - 2);
	}
	while(T--) {
		solve();
	}
}