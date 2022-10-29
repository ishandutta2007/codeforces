#pragma comment(linker, "/STACK:67108864")
 
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)
 
#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
 
using namespace std;
 
typedef long long ll;
 
const long double pi = 3.1415926535897932384626433832795;
const long double eps = 1e-9;
const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
const int MAXN = 22;

ll m, mm;
int n, z[MAXN];
ll dp[MAXN][MAXN], dp2[MAXN][2][MAXN], all[MAXN];
ll ans, tans, cur;
ll fact, inv[MAXN];

ll pw(ll a, ll st) {
	ll p = a, res = 1;
	while (st > 0) {
		if (st & 1) res = (res * p) % MOD;
		st >>= 1;
		p = (p * p) % MOD;
	}
	return res;
}

void get(int n, int sum, int cmax, int len, ll cur) {
	if (n == 0) {
		tans = (tans + cur * fact) % MOD;
		return;
	}

	forn(i, cmax)
		if (sum - i >= 0 && all[i] >= 1)
			get(n - 1, sum - i, i, 1, (cur * all[i]) % MOD);
	if (sum - cmax >= 0 && all[cmax] > len)
		get(n - 1, sum - cmax, cmax, len + 1, (((cur * (all[cmax] - len)) % MOD) * inv[len + 1]) % MOD);
}

int main() {
 
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
 
	fact = 1;
	forab(i, 1, 7) fact *= i;
	forab(i, 2, MAXN) inv[i] = pw(i, MOD - 2);
	cin >> m;
	mm = m;
	n = 0;
	while (mm > 0) {
		mm /= 10;
		n++;
	}
	mm = m;
	forn(i, n) {
		z[n - i - 1] = mm % 10;
		mm /= 10;
	}

	if (n > 1) {
		dp[0][0] = 7;
		dp[0][1] = 2;
	}
	forab(i, 1, n - 1) {
		dp[i][0] = (dp[i][0] + dp[i - 1][0] * 8) % MOD;
		forab(j, 1, MAXN)
			dp[i][j] = (dp[i][j] + dp[i - 1][j] * 8 + dp[i - 1][j - 1] * 2) % MOD;
	}

	forab(i, 1, z[0])
		if (i == 4 || i == 7)
			dp2[0][0][1]++;
		else
			dp2[0][0][0]++;
	if (z[0] == 4 || z[0] == 7)
		dp2[0][1][1]++;
	else
		dp2[0][1][0]++;

	forab(i, 1, n) {
		dp2[i][0][0] = (dp2[i][0][0] + dp2[i - 1][0][0] * 8) % MOD;
		forab(j, 1, MAXN)
			dp2[i][0][j] = (dp2[i][0][j] + dp2[i - 1][0][j] * 8 + dp2[i - 1][0][j - 1] * 2) % MOD;

		forn(j, z[i])
			if (j != 4 && j != 7)
				dp2[i][0][0] = (dp2[i][0][0] + dp2[i - 1][1][0]) % MOD;
		if (z[i] != 4 && z[i] != 7)
			dp2[i][1][0] = (dp2[i][1][0] + dp2[i - 1][1][0]) % MOD;

		forab(j, 1, MAXN) {
			forn(k, z[i]) {
				if (k == 4 || k == 7) {
					dp2[i][0][j] = (dp2[i][0][j] + dp2[i - 1][1][j - 1]) % MOD;
				} else {
					dp2[i][0][j] = (dp2[i][0][j] + dp2[i - 1][1][j]) % MOD;
				}
			}
			if (z[i] == 4 || z[i] == 7) {
				dp2[i][1][j] = (dp2[i][1][j] + dp2[i - 1][1][j - 1]) % MOD;
			} else {
				dp2[i][1][j] = (dp2[i][1][j] + dp2[i - 1][1][j]) % MOD;
			}
		}

	}

	forn(i, n + 1) {
		all[i] = 0;
		forn(j, n - 1)
			all[i] = (all[i] + dp[j][i]) % MOD;
	}
	forn(i, 2)
		forn(j, n + 1)
			all[j] = (all[j] + dp2[n - 1][i][j]) % MOD;

	ans = 0;
	forab(sum, 1, n + 1) {
		tans = 0;
		get(6, sum - 1, sum, 0, 1);
		ans = (ans + tans * all[sum]) % MOD;
	}
	cout << ans;

    return 0;
}