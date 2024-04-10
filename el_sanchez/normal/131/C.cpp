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
typedef vector<int> vi;
typedef pair<int, int> pii;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 11000;

int64 n, m, t, f1, f2, ans;

int main() {

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

	cin >> n >> m >> t;

	f1 = n * (n - 1) * (n - 2) * (n - 3) / (2 * 3 * 4);
	for (int64 i = 4; i <= n; i++) {
		f2 = m;
		for (int64 j = 1; j <= m; j++) {
			if (i + j == t) ans += f1 * f2;
			f2 *= (m - j);
			f2 /= (j + 1);
		}
		f1 *= (n - i);
		f1 /= (i + 1);
	}

	cout << ans;

	return 0;
}