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
const ld eps = 1e-14;
const int INF = 1E9;		                    
const int MAXN = 1111;
                        
int n, w[2], ans;
int dp[MAXN][MAXN];

int main() { 

	cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	forn(i, n) {
		cin >> w[0] >> w[1];
		forn(j, 2) {
		    forn(k, MAXN)
		    	if (dp[i][k] != -1) {
		    		int val = dp[i + 1][max(k, w[0])];
		    		if (val == -1)
		    			val = INF;
		    		dp[i + 1][max(k, w[0])] = min(val, dp[i][k] + w[1]);
		    	}			swap(w[0], w[1]);
		}
	}
	
	ans = INF;
	forn(i, MAXN)
		if (dp[n][i] != -1)
			ans = min(ans, dp[n][i] * i);
	cout << ans;
	
	return 0;
}