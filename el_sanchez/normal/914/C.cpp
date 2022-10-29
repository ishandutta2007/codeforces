#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forab(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

#define FILE_NAME "a"

const int MAXN = (int)1e3 + 5;
const int MOD = (int)1e9 + 7;

int n, k;
string s;
int a[MAXN];
int dp[MAXN][MAXN][2];
int oper[MAXN], came[MAXN];

bool read() {
    if (!(cin >> s)) {
        return 0;
    }
    cin >> k;
    return 1;
}

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
}

int solve() {
	if (k == 0) {
		return 1;
	}
	k--;
	n = sz(s);
	forn(i, n) {
		a[i] = (s[i] - '0');
	}

	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	dp[0][1][1] = 1;

	for (int pos = 0; pos < n - 1; pos++) {
		for (int ones = 0; ones <= n; ones++) {
			for (int eq = 0; eq < 2; eq++) {
				forn(nxt, 2) {
					if ((nxt == 0) || !eq || (eq && nxt <= a[pos + 1])) {
						int nxt_eq = (eq && nxt == a[pos + 1]);
						add(dp[pos + 1][ones + nxt][nxt_eq], dp[pos][ones][eq]);
					}
				}
			}
		}
	}

	memset(came, 0, sizeof(came));
	forn(ones, n + 1) {
		forn(eq, 2) {
			add(came[ones], dp[n - 1][ones][eq]);
		}
	}
	/*
	cout << "---CAME---\n";
	forn(i, n + 1) {
		cout << came[i] << " \n"[i == n];
	}
	cout << "---CAME---\n";
	*/
	oper[1] = 0;
	for (int i = 2; i < MAXN; i++) {
		int bits = 0;
		int x = i;
		while (x > 0) {
			bits += (x & 1);
			x >>= 1;
		}
		oper[i] = oper[bits] + 1;
	}

	int ans = 0;
	for (int i = 1; i < MAXN; i++) {
		if (oper[i] == k) {
			add(ans, came[i]);
		}
	}

	if (k == 0) {
		add(ans, MOD - 1);
	}

	return ans;
}

int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

    while (read()) {
        cout << solve() << '\n';
    }

    return 0;
}