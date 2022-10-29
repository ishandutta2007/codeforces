//#define _GLIBCXX_DEBUG
//#include <bits/stdc++.h>

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>
#include <set>
#include <cassert>
#include <ctime>
               
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 77;
const string sign[5] = {"<", "<=", "=", ">=", ">"};

int n, k, a, b, id;
ll dp[MAXN][MAXN];
bool may[MAXN][MAXN][3];
string s;

int main() {
	
	scanf("%d%d\n", &n, &k);
	n *= 2;
	
	forn(i, n)
		forn(j, n)
			forn(d, 3)
				may[i][j][d] = 1;
				
	forn(i, k) {
		cin >> a >> s >> b;
		a--, b--;

		id = -1;
		forn(d, 5)
			if (s == sign[d])
				id = d;

		if (a > b) {
			swap(a, b);
			id = 4 - id;
		}
		
		if (a == b) {
			if (id == 0 || id == 4) {
				cout << 0;
				return 0;
			}
			continue;
		}
		
		if (id == 0)
			may[a][b][1] = may[a][b][2] = 0;
		if (id == 1)
			may[a][b][2] = 0;
		if (id == 2)
			may[a][b][0] = may[a][b][2] = 0;
		if (id == 3)
			may[a][b][0] = 0;
		if (id == 4)
			may[a][b][0] = may[a][b][1] = 0;
	}

	memset(dp, 0, sizeof(dp));

	for (int i = 0; i + 1 < n; i++)
		if (may[i][i + 1][1])
			dp[i][i + 1] = 1;	
			
	for (int d = 4; d <= n; d += 2) 
		for (int i = 0; i + d <= n; i++) {
			int j = i + d - 1;

			dp[i][j] = 0;
			
			//i, i + 1
			bool ok = 1;
			if (may[i][i + 1][1]) {
				for (int k = i + 2; k <= j; k++)
					if (!(may[i][k][0] && may[i + 1][k][0])) {
						ok = 0;
						break;
					}
				if (ok)
					dp[i][j] += dp[i + 2][j];	
			}	
			
			//i, j
			ok = 1;
			if (may[i][j][1]) {
				for (int k = i + 1; k <= j - 1; k++)
					if (!(may[i][k][0] && may[k][j][2])) {
						ok = 0;
						break;
					}
				if (ok)
					dp[i][j] += dp[i + 1][j - 1];	
			}
			
			//j - 1, j
			ok = 1;
			if (may[j - 1][j][1]) {
				for (int k = i; k <= j - 2; k++)
					if (!(may[k][j - 1][2] && may[k][j][2])) {
						ok = 0;
						break;
					}
				if (ok)
					dp[i][j] += dp[i][j - 2];	
			}		
		}
		
	cout << dp[0][n - 1];
	
	return 0;
}