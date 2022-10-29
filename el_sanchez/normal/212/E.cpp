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
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 5100;

int n, a, b, ans;
bool gr[MAXN][MAXN], used[MAXN], good[MAXN], cgood[MAXN][MAXN];
int dp[MAXN];

void dfs(int v) {
	used[v] = 1;
	dp[v] = 1;
	cgood[v][0] = 1;

	FORN(i, 1, n) 
		if (gr[v][i] && !used[i]) {
			dfs(i);
			dp[v] += dp[i];
			FORD(j, n - dp[i], 0)
				cgood[v][j + dp[i]] |= cgood[v][j];
		}
	
	FORN(i, 1, n)
		if (cgood[v][i])
			good[i] = good[n - i - 1] = 1;
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	forn(i, n - 1) {
		cin >> a >> b;
		gr[a][b] = gr[b][a] = 1;
	}
	dfs(1);

	ans = 0;
	FORN(i, 1, n - 2)
		ans += good[i];

	printf("%d\n", ans);
	FORN(i, 1, n - 2)
		if (good[i])
			printf("%d %d\n", i, n - i - 1);

	return 0;
}