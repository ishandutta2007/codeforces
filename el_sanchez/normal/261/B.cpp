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
const int MAXN = 55;

int n, p, k, sum;
vi a;
long double ans;
long double f[MAXN], dp[MAXN][MAXN];

int main() {

    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

	scanf("%d", &n);
	a.resize(n);
	sum = 0;

	forn(i, n) {
		scanf("%d", &a[i]);
		sum += a[i];
	}

	scanf("%d", &p);

	if (sum <= p) {
		cout << n;
		return 0;
	}

	f[0] = 1;
	forab(i, 1, MAXN)
		f[i] = f[i - 1] * long double(i);

	ans = 0;
	forn(badid, n) {
		forn(i, MAXN)
			forn(j, MAXN)
				dp[i][j] = 0;
		dp[0][0] = 1.0;

		k = 0;
		for (int i = 0; i < n; i++) {
			if (i == badid)
				continue;

			k++;
			for (int j = k - 1; j >= 0; j--)
				for (int w = a[i]; w <= p; w++)
					if (dp[j][w - a[i]] > 0.0)
						dp[j + 1][w] += dp[j][w - a[i]];
		}

		for (int j = 0; j <= k; j++)
			for (int w = 0; w <= p; w++)
				if (w + a[badid] > p)
					ans += dp[j][w] * long double(j) * f[j] * f[n - j - 1];
	}

	ans /= f[n];
	cout.precision(20);
	cout << ans << '\n';

    return 0;
}