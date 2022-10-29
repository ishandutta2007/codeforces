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
const long double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 201000;

int n, m, a, b, cur, cl, t[9];
vector<pii> w;
int pmin[4][MAXN], pmax[4][MAXN];

int main() {

#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif

	cin >> n >> m;
	forn(i, m) {
		cin >> a >> b;
		w.push_back(make_pair(a, b));
	}

	forn(i, 4) forn(j, 2 * n + 1) pmin[i][j] = n + 1;

	forn(i, m) {
		cl = w[i].first;
		pmin[0][cl] = min(pmin[0][cl], w[i].second);
		pmax[0][cl] = max(pmax[0][cl], w[i].second);
	}
	forn(i, m) {
		cl = w[i].second;
		pmin[1][cl] = min(pmin[1][cl], w[i].first);
		pmax[1][cl] = max(pmax[1][cl], w[i].first);
	}
	forn(i, m) {
		cl = w[i].first + w[i].second;
		pmin[2][cl] = min(pmin[2][cl], w[i].first);
		pmax[2][cl] = max(pmax[2][cl], w[i].first);
	}
	forn(i, m) {
		cl = w[i].first + (n - w[i].second + 1);
		pmin[3][cl] = min(pmin[3][cl], w[i].first);
		pmax[3][cl] = max(pmax[3][cl], w[i].first);
	}
	
	forn(i, m) {
		cur = 0;
		cl = w[i].first;
		cur += (pmin[0][cl] < w[i].second);
		cur += (pmax[0][cl] > w[i].second);
		cl = w[i].second;
		cur += (pmin[1][cl] < w[i].first);
		cur += (pmax[1][cl] > w[i].first);
		cl = w[i].first + w[i].second;
		cur += (pmin[2][cl] < w[i].first);
		cur += (pmax[2][cl] > w[i].first);
		cl = w[i].first + (n - w[i].second + 1);
		cur += (pmin[3][cl] < w[i].first);
		cur += (pmax[3][cl] > w[i].first);
		t[cur]++;
	}

	forn(i, 9)
		cout << t[i] << ' ';
	cout << endl;

	return 0;
}