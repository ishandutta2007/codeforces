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
const int MAXN = 111;

int n;
vector<long double> p;
long double xq, xsum, x2sum, mn, ans, nw;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	scanf("%d", &n);
	p.resize(n + 2);
	p[0] = 0;
	forn(i, n)
		scanf("%lf", &p[i + 1]);
	p[n + 1] = 0;

	ans = 0;
	forab(i, 1, n + 1) {
		nw = (1 - p[i - 1]) * p[i];
		xq = (xq + xsum + x2sum) * p[i] + nw;
		x2sum = (x2sum + 2.0 * xsum) * p[i] + 2.0 * nw;
		xsum = xsum * p[i] + nw;
		ans += xq * (1.0 - p[i + 1]);		
	}
	cout.precision(100);
	cout << ans;

	return 0;
}