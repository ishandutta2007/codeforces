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
const int MAXN = 333333;

int n, m, l, r, ans, ct;
vi a;

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cin >> n >> m;
	a.resize(n);
	forn(i, n)
		cin >> a[i];

	l = r = 0;
	ct = a[0];
	ans = 0;
	for (l = 0; l < n; l++) {
		if (r < l) {
			r = l;
			ct = a[l];
		}

		while (r < n - 1 && ct + a[r + 1] <= m) {
			ct += a[r + 1];
			r++;
		}

		if (ct <= m)
			ans = max(ans, r - l + 1);

		ct -= a[l];
	}
	cout << ans;

	return 0;
}