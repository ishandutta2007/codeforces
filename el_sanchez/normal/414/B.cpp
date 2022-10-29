#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <cassert>
                   
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++) 
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = int(a); i < int(b); i++)

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 1E9;   
const ld eps = 1e-7;
const int MAXN = 2222;   
const int MOD = 1E9 + 7;
                 
int n, m;
int dp[MAXN][MAXN];
                       
int main() {

	cin >> n >> m;
	/*
	int k = 0;
	forn(i, 2000)
		k += 2000 / (i + 1);
	cout << k;		
	*/

	forn(i, n)
		dp[0][i + 1] = 1;

    forn(i, m - 1) {
    	for (int j = 1; j <= n; j++) {
    		int t = dp[i][j];
    	 	for (int k = j; k <= n; k += j) {
    	 		dp[i + 1][k] += t;
    	 		if (dp[i + 1][k] >= MOD)
    	 			dp[i + 1][k] -= MOD;
    	 	}
    	}	
   	}

    int sum = 0;
    forab(i, 1, n + 1)
    	sum = (sum + dp[m - 1][i]) % MOD;
   	cout << sum;
   	            	                      
    return 0;
}