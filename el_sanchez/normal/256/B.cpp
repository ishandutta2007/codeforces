#pragma comment(linker, "/STACK:67108864")
 
#include <iostream>
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
 
const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 4010;

ll n, x, y, c;

bool good(ll a) {
	a++;
	ll big_sqr = 2 * a * (a - 1) + 1;

	ll small_sqr, d;
	//left
	if (x - a < 0) {
		d = a - x;
		small_sqr = d * d;
		big_sqr -= small_sqr;
	}
	//right
	if ((n - x + 1) - a < 0) {
		d = a - (n - x + 1);
		small_sqr = d * d;
		big_sqr -= small_sqr;
	}
	//up
	if (y - a < 0) {
		d = a - y;
		small_sqr = d * d;
		big_sqr -= small_sqr;
	}
	//down
	if ((n - y + 1) - a < 0) {
		d = a - (n - y + 1);
		small_sqr = d * d;
		big_sqr -= small_sqr;
	}

	ll very_small_sqr;
	//corners
	if (x + y < a) {
		d = a - x - y;
		very_small_sqr = d * (d + 1) / 2;
		big_sqr += very_small_sqr;
	}
	if ((n - x + 1) + y < a) {
		d = a - (n - x + 1) - y;
		very_small_sqr = d * (d + 1) / 2;
		big_sqr += very_small_sqr;
	}
	if (x + (n - y + 1) < a) {
		d = a - x - (n - y + 1);
		very_small_sqr = d * (d + 1) / 2;
		big_sqr += very_small_sqr;
	}
	if ((n - x + 1) + (n - y + 1) < a) {
		d = a - (n - x + 1) - (n - y + 1);
		very_small_sqr = d * (d + 1) / 2;
		big_sqr += very_small_sqr;
	}
	ll ans = big_sqr;

	return (ans >= c);
}

ll binsrch() {
	ll l = -1, r = 2 * INF + 100;
	ll mid;
	while (l + 1 < r) {
		mid = (l + r) / 2;
		if (good(mid))
			r = mid;
		else
			l = mid;
	}
	return r;
}

int main() {
 
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
 
	cin >> n >> x >> y >> c;
	cout << binsrch() << '\n';

    return 0;
}