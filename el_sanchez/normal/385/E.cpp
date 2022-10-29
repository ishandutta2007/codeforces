#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream> 
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
#include <ctime>
#include <cfloat>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const long double pi = acos(-1.0);
const long double eps = 1e-6;
const int INF = 1E9;
const int MAXN = 100500;

ll n, sx, sy, dx, dy, t;
vector<vector<ll>> a, b;

vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>> ans;
	ans.clear();
	ans.resize(5);
	forn(i, 5)
		ans[i].resize(5, 0);

	forn(i, 5)
		forn(j, 5)
			forn(k, 5)
				ans[i][k] = (ans[i][k] + a[i][j] * b[j][k]) % n;

	return ans;
}

vector<vector<ll>> binpow(vector<vector<ll>> a, ll m) {
	vector<vector<ll>> ans;
	ans.clear();
	ans.resize(5);
	forn(i, 5)
		ans[i].resize(5, 0);
	forn(i, 5)
		ans[i][i] = 1;

	while (m > 0) {
		if (m & 1)
			ans = mul(ans, a);
		m >>= 1;
		a = mul(a, a);
	}

	return ans;
}

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	cin >> n >> sx >> sy >> dx >> dy >> t;
	sx--, sy--;
	sx = (n + sx) % n;
	sy = (n + sy) % n;
	dx = (n + dx) % n;
	dy = (n + dy) % n;
	
	a.resize(5);
	forn(i, 5)
		a[i].resize(5, 0);
	b = a;

	a[0] = {sx, sy, 0, 0, 1};

	b[0] = {1 + 1, 0 + 1, 1, 0, 0};
	b[1] = {0 + 1, 1 + 1, 1, 0, 0};
	b[2] = {1, 1, 1, 0, 0};
	b[3] = {0 + 1, 0 + 1, 1, 1, 0};
	b[4] = {dx + 2, dy + 2, 2, 1, 1};

	b = binpow(b, t);
	a = mul(a, b);
	cout << a[0][0] + 1 << ' ' << a[0][1] + 1 << '\n';

	return 0;
}