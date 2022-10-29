#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 111;
const int MAXM = 11111;

int n, m, k, ans, cans, cur, cmv;
int lm[MAXN], rm[MAXN], dp[MAXN][MAXM];
bool good, cgd;
string s[MAXN];

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	scanf("%d%d\n", &n, &m);
	good = 1;
	forn(i, n) {
		cin >> s[i];
		cgd = 0;
		lm[i] = INF;
		rm[i] = -INF;
		forn(j, m)
			if (s[i][j] == '1') {
				cgd = 1;
				lm[i] = min(lm[i], j);
				rm[i] = max(rm[i], j);
			}
		good &= cgd;
	}

	if (!good) {
		cout << -1;
		return 0;
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}

	forn(i, n) {
		forn(j, m)
			dp[i][j] = INF;

		cur = -INF;
		forn(j, m) {
			if (s[i][j] == '1') {
				cur = j;
				dp[i][j] = 0;
			} else {
				dp[i][j] = min(dp[i][j], min(j - cur, m - rm[i] + j));
			}
		}

		cur = INF;
		ford(j, m) {
			if (s[i][j] == '1') {
				cur = j;
				dp[i][j] = 0;
			} else {
				dp[i][j] = min(dp[i][j], min(cur - j, lm[i] + m - j));
			}
		}
	}

	ans = INF;
	forn(i, m) {
		cans = 0;
		forn(j, n) 
			cans += dp[j][i];
		ans = min(cans, ans);
	}
	cout << ans;

	return 0;
}