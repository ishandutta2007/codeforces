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
#include <ctime>

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

typedef long long ll;

const double pi = 3.1415926535897932384626433832795;
const double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 8388608 + 10;

inline int bit(int x, int k) {
	return (x >> k) & 1;
}

int n, mmask, ans, cv;
bool ok;
vi a;
vector<vi> good;
int dp[MAXN];

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	forn(i, MAXN)
		dp[i] = INF;
	cin >> n;
	a.resize(n);
	forn(i, n)
		cin >> a[i];
	good.resize(n);

	for (int k = 1; k < n; k++)
		for (int i = 0; i < k; i++)
			for (int j = i; j < k; j++)
				if (a[i] + a[j] == a[k])
					good[k].push_back((1 << i) | (1 << j));

	mmask = 1 << n;
	dp[1] = 1;
	ans = INF;
	for (int cmask = 1; cmask < mmask; cmask++) {
		if (dp[cmask] == INF)
			continue;

		cv = 0;
		forn(i, n)
			if (bit(cmask, i))
				cv = i;

		if (cv == n - 1)
			ans = min(ans, dp[cmask]);
		else {
			cv++;

			ok = 0;
			forn(i, good[cv].size())
				if ((cmask & good[cv][i]) == good[cv][i]) {
					ok = 1;
					break;
				}

			if (ok) {
				dp[cmask + (1 << cv)] = min(dp[cmask + (1 << cv)], dp[cmask] + 1);
				forn(i, cv)
					if (bit(cmask, i))
						dp[cmask - (1 << i) + (1 << cv)] = min(dp[cmask - (1 << i) + (1 << cv)], dp[cmask]);
			}
		}
	}

	cout << (ans == INF ? -1 : ans);

	return 0;
}