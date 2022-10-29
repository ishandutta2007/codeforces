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
const int MAXN = 100;

int n, m, k, mm, cmp;
string w[MAXN];
bool used[MAXN][MAXN];

void dfs(int i, int j) {
	used[i][j] = 1;
	if (i > 0 && w[i - 1][j] == '#' && !used[i - 1][j]) dfs(i - 1, j);
	if (i < n - 1 && w[i + 1][j] == '#' && !used[i + 1][j]) dfs(i + 1, j);
	if (j > 0 && w[i][j - 1] == '#' && !used[i][j - 1]) dfs(i, j - 1);
	if (j < m - 1 && w[i][j + 1] == '#' && !used[i][j + 1]) dfs(i, j + 1);
}

int main() {

	scanf("%d%d\n", &n, &m);
	forn(i, n)
		cin >> w[i];
	
	forn(i, n)
		forn(j, m)
			if (w[i][j] == '#')
				k++;

	if (k <= 2)
		cout << -1;
	else {
		mm = INF;
		forn(i, n)
			forn(j, m)
				if (w[i][j] == '#') {
					w[i][j] = '.';
					cmp = 0;
					forn(ii, n) forn(jj, m) used[ii][jj] = 0;

					forn(ii, n)
						forn(jj, m)
							if (w[ii][jj] == '#' && !used[ii][jj]) {
								cmp++;
								dfs(ii, jj);
							}

					if (cmp > 1) {
						cout << 1;
						return 0;
					}
					w[i][j] = '#';
				}
		cout << 2;
	}
			
	return 0;
}