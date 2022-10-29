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
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 500500;

int n, maxl, t;
vector<pii> a;
int sz;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	
	cin >> n;
	a.resize(n);
	forn(i, n)
		cin >> a[i].ff >> a[i].ss;
	maxl = t = 0;
	sz = 0;

	forn(i, n) {
		if (t <= a[i].ff) {
			sz = a[i].ss;
			t = a[i].ff + sz;
		} else {
			sz = max(0, sz - (a[i].ff - a[i - 1].ff));
			sz += a[i].ss;
			t += a[i].ss;
		}
		maxl = max(maxl, sz);
	}

	cout << t << ' ' << maxl << '\n';

    return 0;
}