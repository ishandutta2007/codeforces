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

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-12;
const int INF = 1E9;		
const int MAXN = 3333;
                                                                         
int n, m;
vi g[5][MAXN];
ll dp[2][MAXN][MAXN], ans, cur;

int main() {

	cin >> n >> m;
	int a, b;
	forn(i, m) {
		cin >> a >> b;
		a--, b--;
		g[0][a].pb(b);
		g[1][a].pb(b);
		g[2][b].pb(a);
		g[3][b].pb(a);
	}
	
	forn(i, n)
		dp[0][i][i] = 1;

	ans = 0;
	
	int id = 1;
	for (int k = 0; k <= 3; k++) {
		forn(i, n)
			forn(j, n)
				dp[id][i][j] = 0;
				
		forn(i, n)
			forn(j, n)
				if (dp[id ^ 1][i][j] != 0) {
				    for (auto v: g[k][j]) {
				    	if (k == 3) {
				    	    dp[id][i][v] += dp[id ^ 1][i][j];
				    	} else {
				    		if (i != v)
				    			dp[id][i][v] += dp[id ^ 1][i][j];
				    	}
				    }				
				}
		
		if (k == 3)
			forn(i, n)
				ans += dp[id][i][i];
		if (k == 1)
			forn(i, n)
				forn(j, n)
					ans -= dp[id][i][j];
		
		id ^= 1;
	}
				
	cout << ans / 2;
	
	return 0;
}