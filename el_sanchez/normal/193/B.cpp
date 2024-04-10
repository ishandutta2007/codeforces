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

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.00000001;
const int INF = 1E9;
const int MAXN = 50;

int64 ans, cans;
int n, m, r;
int a[MAXN], b[MAXN], k[MAXN], p[MAXN], tmp[MAXN];
int cur[MAXN][MAXN];

void get(int v, int pr) { 
	if ((v & 1) == (m & 1)) {
		cans = 0;
		FORN(i, 1, n)
			cans += 1ll * a[i] * k[i];
		if (ans < cans) ans = cans;
	}
	if (v == m) return;

	FORN(i, 1, n)
		cur[v][i] = a[i];
	FORN(i, 1, n)
		a[i] = (cur[v][p[i]] + r);
	get(v + 1, 1);

	if (pr != 0) {		
		FORN(i, 1, n)
			a[i] = (cur[v][i] ^ b[i]);
		get(v + 1, 0);
	}
}

int main() {

	ans = -1E18;
	cin >> n >> m >> r;
	forn(i, n) cin >> a[i + 1];
	forn(i, n) cin >> b[i + 1];
	forn(i, n) cin >> k[i + 1];
	forn(i, n) cin >> p[i + 1];
	get(0, -1);
	cout << ans;

	return 0;
}