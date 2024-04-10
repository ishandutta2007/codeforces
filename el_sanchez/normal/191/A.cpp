#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.00000001;
const int INF = 1E9;
const int MAXN = 30;

int n, l, a[2], dp[MAXN][MAXN];
string s;

int main() {

	//freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
	
	scanf("%d\n", &n);
	forn(i, MAXN)
		forn(j, MAXN)
			dp[i][j] = -1;

	forn(i, n) {
		cin >> s;
		l = s.size();
		a[0] = s[0] - 'a';
		a[1] = s[l - 1] - 'a';
		forn(j, MAXN)
			if (dp[j][a[0]] != -1)
				dp[j][a[1]] = max(dp[j][a[1]], dp[j][a[0]] + l);
		dp[a[0]][a[1]] = max(dp[a[0]][a[1]], l);
	}

	a[0] = 0;
	forn(i, MAXN)
		a[0] = max(a[0], dp[i][i]);
	cout << a[0];
	return 0;
}