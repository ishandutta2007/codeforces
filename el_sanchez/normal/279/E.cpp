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
const int MAXN = 1000010;

int n, ans;
bool a[MAXN];
int dp[MAXN][2];
string s;

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cin >> s;
	n = s.size();
	while (n > 0 && s[n - 1] == '0')
		n--;
	n--;

	if (n <= 0) {
		cout << 1;
		return 0;
	}

	a[0] = 0;
	forn(i, n)
		a[i + 1] = s[i] - '0';
	n++;

	forn(i, MAXN)
		forn(j, 2)
			dp[i][j] = INF;
	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 1; i < n; i++) {
		//not invert
		if (a[i]) //1
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + 1);
		else { //0
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][0]);
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 1);
		}
		//invert
		if (!a[i]) { //1! 
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + 1);
		} else { //0
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][1]);
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 1);
		}
	}

	ans = min(dp[n][0], dp[n][1]);
	cout << ans + 1;

	return 0;
}