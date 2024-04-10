#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;
const int MAXN = 11111;
const ll MOD = 1E9 + 7;

int n;
ll dp[MAXN][8];
string s[3];
pii p, need[4][2];
int ans;
bool can[4];

int bit(int mask, int k) {
	return (mask >> k) & 1;
}

void addto(int k, int mask, int i, int nmask) {
	if (i >= 3) {
		dp[k + 1][nmask] = (dp[k + 1][nmask] + dp[k][mask]) % MOD;
		return;
	}

	if (bit(mask, i))
		addto(k, mask, i + 1, nmask);
	else {
		if (s[i][k] == 'X')
			addto(k, mask, i + 1, nmask);
		else {
			if (s[i][k + 1] != 'X' && !(s[i][k] == '-' && s[i][k + 1] == '-'))
				addto(k, mask, i + 1, nmask + (1 << i));
			if (i <= 1 && !bit(mask, i + 1) && s[i + 1][k] != 'X' && !(s[i][k] == '-' && s[i + 1][k] == '-'))
				addto(k, mask, i + 2, nmask);
		}
	}
}

ll get(int smask) {
	forn(i, 4)
		if (can[i]) {
			if (bit(smask, i)) {
				s[need[i][0].ff][need[i][0].ss] = 'X';
				s[need[i][1].ff][need[i][1].ss] = 'X';
			} else {
				s[need[i][0].ff][need[i][0].ss] = '-';
				s[need[i][1].ff][need[i][1].ss] = '-';
			}
		}

	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int mask = 0; mask < 8; mask++)
			if (dp[i][mask]) {
				//bruteforce
				addto(i, mask, 0, 0);
			}

	forn(i, 4)
		if (can[i]) {
			s[need[i][0].ff][need[i][0].ss] = '.';
			s[need[i][1].ff][need[i][1].ss] = '.';
		}

	return dp[n][0];
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	forn(i, 3) {
		cin >> s[i];
		s[i] += 'X';
	}
	forn(i, 3)
		forn(j, n)
			if (s[i][j] == 'O')
				p.ff = i, p.ss = j;

	ans = 0;
	s[p.ff][p.ss] = 'X';

	//left
	can[0] = p.ss >= 2 && s[p.ff][p.ss - 1] == '.' && s[p.ff][p.ss - 2] == '.';
	need[0][0] = make_pair(p.ff, p.ss - 1);
	need[0][1] = make_pair(p.ff, p.ss - 2);
	
	//right
	can[1] = p.ss <= n - 3 && s[p.ff][p.ss + 1] == '.' && s[p.ff][p.ss + 2] == '.';
	need[1][0] = make_pair(p.ff, p.ss + 1);
	need[1][1] = make_pair(p.ff, p.ss + 2);

	//up
	can[2] = p.ff == 2 && s[p.ff - 1][p.ss] == '.' && s[p.ff - 2][p.ss] == '.';
	need[2][0] = make_pair(p.ff - 1, p.ss);
	need[2][1] = make_pair(p.ff - 2, p.ss);

	//down
	can[3] = p.ff == 0 && s[p.ff + 1][p.ss] == '.' && s[p.ff + 2][p.ss] == '.';
	need[3][0] = make_pair(p.ff + 1, p.ss);
	need[3][1] = make_pair(p.ff + 2, p.ss);

	forn(i, 4)
		if (can[i])
			ans = (ans + get(1 << i)) % MOD;

	forn(i, 4)
		forab(j, i + 1, 4)
			if (can[i] && can[j]) {
				ans = (ans + get((1 << i) + (1 << j))) % MOD;
			}

	forn(i, 4)
		forab(j, i + 1, 4)
			forab(k, j + 1, 4) 
				if (can[i] && can[j] && can[k]) {
					ans = (ans + get((1 << i) + (1 << j) + (1 << k))) % MOD;
				}

	cout << ans << '\n';

	return 0;
}