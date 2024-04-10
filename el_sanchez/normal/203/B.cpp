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
#include <map>
#include <set>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define fi first
#define se second

using namespace std;

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.0000001;
const int INF = 1E9;
const int MAXN = 2000;

int n, m, a, b;
bool w[MAXN][MAXN], good;

int main() {

	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);

	scanf("%d%d", &n, &m);
	forn(i, m) {
		scanf("%d%d", &a, &b);
		a += 3; 
		b += 3;
		w[a][b] = 1;
		FORN(ii, a - 2, a)
			FORN(jj, b - 2, b) {
				good = 1;
				FORN(i1, ii, ii + 2)
					FORN(j1, jj, jj + 2)
						good &= w[i1][j1];
				if (good) {
					cout << i + 1;
					return 0;
				}
			}
	}
	cout << -1;

	return 0;
}