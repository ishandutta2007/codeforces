#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

// MAGIC IO
inline char get(void) {
	static char buf[100000], *S = buf, *T = buf;
	if (S == T) {
		T = (S = buf) + fread(buf, 1, 100000, stdin);
		if (S == T) return EOF;
	}
	return *S++;
}
inline void read(int &x) {
	static char c; x = 0; int sgn = 0;
	for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
	for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
	if (sgn) x = -x;
}
void readchar(char& c) {
	while (isspace(c = get()));
}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 4000 + 2;
const int K = 800 + 2;
int val[N][N];
int pref[N][N];
int cost[N][N];
int dp[K][N];

void solve(int i, int lj, int rj, int left, int right) {
	if (lj > rj) return;

	int mid = (lj+rj)/2;
	//cerr << "  id range " << lj << " " << rj << " w/ candidates " << left << " " << right << " ; mid " << mid << endl;
	dp[i][mid] = INF;
	int best = -1;
	for (int j = left; j <= min(mid, right); j++) {
		if (dp[i-1][j] + cost[j+1][mid] < dp[i][mid]) {
			dp[i][mid] = dp[i-1][j] + cost[j+1][mid];
			best = j;
		}
	}
	//cerr << "    best: " << best << endl;
	//assert(best != -1);
	solve(i, lj, mid-1, left, best);
	solve(i, mid+1, rj, best, right);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);

	int n, k;
	//cin >> n >> k;
	read(n); read(k);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//cin >> val[i][j];
			read(val[i][j]);
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + val[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			cost[i][j] = pref[j][j] - pref[i-1][j] - pref[j][i-1] + pref[i-1][i-1];
		}
	}

	memset(dp[0], INF, sizeof dp[0]);
	dp[0][0] = 0;
	for (int i = 1; i <= k; i++) {
		//cerr << "solve layer " << i << endl;
		solve(i, 1, n, 0, n);
	}

	cout << dp[k][n]/2 << nl;

	return 0;
}