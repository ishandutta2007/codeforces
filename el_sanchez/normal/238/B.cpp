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

const long double pi = acos(0.0) * 2.0;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 1E5;

int n, m, id, aval, cval, cmin, cmax;
vector<pii> a;
vi ans;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n >> m;
	a.resize(n);
	ans.resize(n);
	forn(i, n) {
		scanf("%d", &a[i].ff);
		a[i].ss = i;
	}
	sort(all(a));

	id = 0;
	cmax = a[n - 1].ff + a[n - 2].ff;
	cmin = a[0].ff + a[1].ff;
	aval = cmax - cmin;

	if (n > 2) {
		cmax = max(cmax, a[0].ff + a[n - 1].ff + m);
		cmin = min(a[1].ff + a[2].ff, a[0].ff + a[1].ff + m);
		cval = cmax - cmin;
		if (aval > cval) {
			aval = cval;
			id = -1;
		}
	}

	forab(i, 1, n - 2) {
		cmin = min(a[0].ff + a[i + 1].ff, a[0].ff + a[1].ff + m);
		cmax = max(a[n - 1].ff + a[n - 2].ff, a[i].ff + a[n - 1].ff + m);
		if (i != 1)
			cmin = min(cmin, a[1].ff + a[2].ff);
		cval = cmax - cmin;
		if (aval > cval) {
			aval = cval;
			id = i;
		}
	}

	forn(i, n)
		ans[i] = 1;
	if (id >= 1)
		forab(i, 1, id + 1)
			ans[a[i].ss] = 2;
	if (id == -1)
		ans[a[0].ss] = 2;
		
	cout << aval << '\n';
	forn(i, n)
		printf("%d ", ans[i]);

	return 0;
}