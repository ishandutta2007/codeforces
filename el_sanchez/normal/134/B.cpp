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
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 5000;

int n, k, d, cur, ans;

int gcd(int a, int b) {
	if (a == 0 || b == 0) return a + b;
	if (a > b) {
		cur += (a - 1) / b;
		return gcd(a % b, b);
	}
	cur += (b - 1) / a;
	return gcd(a, b % a);
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

	cin >> n;
	ans = INF;
	FORN(k, 1, 2 * n + 1) {
		cur = 0;
		d = gcd(n, k);
		if (d == 1)
			ans = min(ans, cur);
	}
	cout << ans;

    return 0;
}