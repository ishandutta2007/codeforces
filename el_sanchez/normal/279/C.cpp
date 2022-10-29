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

int n, m, cur, l, r;
int cmin, cmax;
vi a;
vi up, dno;

int main() {
	
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cin >> n >> m;
	a.resize(n);
	forn(i, n)
		scanf("%d", &a[i]);

	up.resize(n);
	dno.resize(n);
	cmin = cmax = n - 1;
	up[n - 1] = dno[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] > a[i + 1])
			cmax = i;
		up[i] = cmax;

		if (a[i] < a[i + 1])
			cmin = i;
		dno[i] = cmin;
	}

	forn(i, m) {
		scanf("%d%d", &l, &r);
		l--, r--;
		if (dno[up[l]] >= r)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}