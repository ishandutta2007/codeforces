#include <bits/stdc++.h>

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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;        
const int MAXN = 511;

int n, m, b, mod, ans;
int a[MAXN];
int dp[MAXN][MAXN];

int main() {

	cin >> n >> m >> b >> mod;
	forn(i, n)
		cin >> a[i];

	dp[0][0] = 1;
	forn(i, n) {
		forn(j, m)
	    	forn(k, b + 1)
	    		if (dp[j][k] != 0 && k + a[i] <= b) {
	    			dp[j + 1][k + a[i]] += dp[j][k];
	    			if (dp[j + 1][k + a[i]] >= mod)
	    				dp[j + 1][k + a[i]] -= mod;		
	    		}			
		
	}	
	
	ans = 0;
	forn(k, b + 1)
		ans = (ans + dp[m][k]) % mod;
	cout << ans;		
	return 0;
}