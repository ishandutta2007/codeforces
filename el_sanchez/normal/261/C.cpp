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
#define mp make_pair
#define pb push_back
 
using namespace std;
 
typedef long long ll;
 
const long double pi = 3.1415926535897932384626433832795;

const long double eps = 1e-9;
const int INF = int(1e9);
const ll LINF = ll(1e18);
const int MAXN = 100;

ll n, t, k, x, st;
ll dp[MAXN][MAXN], sum[MAXN][MAXN], ans;

void getans(ll p, ll x, ll pos) {
	if (p == 0)
		return;
	if (p == 1) {
		if (x == 0) ans++;
		if (x == 1 && pos == 1) ans++;
		return;
	}

	//pos from 0!
	ll dist = (1ll << p);
	if (pos < (dist >> 1))
		getans(p - 1, x, pos);
	else {
		ans += dp[p - 1][x];
		getans(p - 1, x - 1, pos - (dist >> 1));
	}
}

int main() {

    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

	cin >> n >> t;

	if (n == 1) {
		cout << (t == 1 ? 1 : 0) << '\n';
		return 0;
	}

	k = 1;
	st = 0;
	while (k < t) {
		k <<= 1;
		st++;
	}
	if (k != t) {
		cout << 0;
		return 0;
	}

	//dp[x][y]: [(2^x)-1..2^(x+1)-2]
	forn(i, MAXN)
		dp[1][i] = 0;
	dp[1][0] = sum[1][0] = 1;
	dp[1][1] = sum[1][1] = 1;
	forab(i, 2, MAXN) {
		forn(j, MAXN)
			dp[i][j] = dp[i - 1][j];
		forab(j, 1, MAXN)
			dp[i][j] += dp[i - 1][j - 1];
		forn(j, MAXN)
			sum[i][j] = sum[i - 1][j] + dp[i][j];
	}

	x = 1;
	k = 2;
	while ((k * 2 - 2) <= n) {
		x++;
		k <<= 1;
	}

	ans = sum[x - 1][st];
	getans(x, st, n - k + 1);
	cout << ans << '\n';

    return 0;
}