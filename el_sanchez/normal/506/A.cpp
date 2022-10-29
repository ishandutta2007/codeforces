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
#include <cfloat>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;
const int MAXN = 30000;
const int MAXK = 300;

int n, d, k;
int a[MAXN + 100], ans;
int dp[MAXN + 100][MAXK * 2 + 3];

int main() {

	cin >> n >> d;
	forn(i, n) {
		cin >> k;
		a[k]++;
	}
	
	memset(dp, -1, sizeof(dp));
	
	dp[d][MAXK] = a[d];
	for (int i = d; i <= MAXN; i++) {
		for (int k = 0; k <= 2 * MAXK; k++) 
			if (dp[i][k] != -1) {
				int cur = d - (MAXK - k);
				
				if (i + cur - 1 <= MAXN && k > 0 && cur - 1 > 0)
					dp[i + cur - 1][k - 1] = max(dp[i + cur - 1][k - 1], dp[i][k] + a[i + cur - 1]);
				if (i + cur <= MAXN && cur > 0)
					dp[i + cur][k] = max(dp[i + cur][k], dp[i][k] + a[i + cur]);
				if (i + cur + 1 <= MAXN && k < 2 * MAXK && cur > 0)
					dp[i + cur + 1][k + 1] = max(dp[i + cur + 1][k + 1], dp[i][k] + a[i + cur + 1]);
				
			}
			
	}
	
	ans = 0;
	for (int i = 0; i <= MAXN; i++)
		forn(j, MAXK * 2 + 3)
			ans = max(ans, dp[i][j]);
	cout << ans;
	
	
	return 0;
}