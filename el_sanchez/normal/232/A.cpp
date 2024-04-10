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
const int MAXN = 100;

int i, j, n, k, dp[MAXN + 10], dp2[MAXN + 10];
int g[MAXN + 10][MAXN + 10];

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> k;
	forab(i, 1, MAXN + 1) {
		dp[i] = i * (i - 1) * (i - 2) / 6;
		dp2[i] = i * (i - 1) / 2;
	}

	i = 1;
	while (dp[i] <= k)
		i++;
	i--;
	n = i;
	forn(i, n)
		forn(j, n)
			if (i != j)
				g[i][j] = 1;

	k -= dp[n];
	while (k > 0) {
		j = 1;
		while (dp2[j] <= k)
			j++;
		j--;
		forn(i, j)
			g[n][i] = g[i][n] = 1;
		n++;
		k -= dp2[j];
	}

	printf("%d\n", n);
	forn(i, n) {
		forn(j, n)
			cout << g[i][j];
		cout << '\n';
	}

	return 0;
}