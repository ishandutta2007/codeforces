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
const int MAXN = 511;
                    
int n, m, MOD, cnt[3], a[MAXN];
int dp[MAXN][MAXN];
int pp1[MAXN], pq[MAXN][MAXN];
string s;

int main() {
	
	cin >> n >> m >> MOD;
	forn(i, m) {
		cin >> s;
		forn(j, n)
			if (s[j] == '1')
				a[j]++;
	}
	
	forn(i, n + 1) {
		ll res = 1ll * i * (i - 1) / 2;
		res %= MOD;
		pp1[i] = res;	
	}
	
	forn(i, n + 1)
		forn(j, n + 1) {
			ll res = 1ll * i * j;
			res %= MOD;
			pq[i][j] = res;		
		}
				
	forn(i, n)
		cnt[a[i]]++;
		
	dp[cnt[0]][cnt[1]] = 1;
	forn(i, n - m) {
		for (int q = 0; q <= n; q++)
			for (int p = 0; p <= n; p++) 
				if (dp[q][p] != 0) {
					if (q >= 2) {
						ll cur = 1ll * dp[q][p] * pp1[q] + dp[q - 2][p + 2];
						dp[q - 2][p + 2] = cur % MOD;
					}
					if (q >= 1) {
						ll cur = 1ll * dp[q][p] * pq[q][p] + dp[q - 1][p];
						dp[q - 1][p] = cur % MOD;
					}
					if (p >= 2) {
						ll cur = 1ll * dp[q][p] * pp1[p] + dp[q][p - 2];
						dp[q][p - 2] = cur % MOD;
					}
				}
			
	}	
	
	cout << dp[0][0];
                    	
	return 0;
}