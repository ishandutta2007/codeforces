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

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 111;

int n, k, a, aa, b, bb;
vi q, s, p, pp, pn;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	scanf("%d%d", &n, &k);
	q.resize(n + 1);
	s.resize(n + 1);
	p.resize(n + 1);
	pn.resize(n + 1);
	forn(i, n) scanf("%d", &q[i + 1]);
	forn(i, n) scanf("%d", &s[i + 1]);
	forn(i, n) p[i + 1] = i + 1;

	if (p == s) {
		cout << "NO";
		return 0;
	}
	a = b = INF;

	pp = p;
	forn(i, k) {
		forab(j, 1, n + 1)
			pn[j] = p[q[j]];
		p = pn;

		if (p == s && a == INF)
			a = i + 1;
		//if (p == pp && aa == 0)
		//	aa = i + 1;
		//forab(j, 1, n + 1)
		//	cout << p[j] << ' ';
		//cout << '\n';
	}

	p = pp;
	forn(i, k) {
		forab(j, 1, n + 1)
			pn[q[j]] = p[j];
		p = pn;

		if (p == s && b == INF)
			b = i + 1;
		//if (p == pp && bb == 0)
		//	bb = i + 1;
	}

	if (a == INF && b == INF || a == 1 && b == 1 && k != 1) {
		cout << "NO";
		return 0;
	}
	if ((a != INF && abs(a - k) % 2 == 0) || (b != INF && abs(b - k) % 2 == 0)) {
		cout << "YES";
		return 0;
	} else {
		cout << "NO";
		return 0;
	}

    return 0;
}