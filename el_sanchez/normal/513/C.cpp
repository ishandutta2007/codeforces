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
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 11111;

int n, maxc;
int l[MAXN], r[MAXN], b[MAXN];
int _less[MAXN];
int id[MAXN], mx;
ld ans, dp[11][MAXN], sum[11][MAXN];
ld p[11];

int main() {

	cin >> n;
	forn(i, n) {
		cin >> l[i] >> r[i]; 
		p[i] = 1.0 / (r[i] - l[i] + 1);
	}

	forn(i, n)
		id[i] = i;
			
	ans = 0;
	
	while (true) {
	    maxc = 1 << (n - 1);
	    forn(mask, maxc) {
	    	forn(i, n - 1)
	    		_less[i] = (mask >> i) & 1;

	    	bool ok = 1;
	    	forn(i, n - 1)
	    		if (_less[i] == 1 && id[i] > id[i + 1]) {
	    			ok = 0;
	    			break;
	    		}
	    		
	    	if (!ok)
	    		continue;
	    		
	    	memset(dp, 0, sizeof(dp));
	    	
	    	for (int i = l[id[n - 2]]; i <= r[id[n - 2]]; i++) {
	    		dp[n - 2][i] = 1.0 * i;
	    		if (_less[n - 2])
	    			dp[n - 2][i] *= (l[id[n - 1]] <= i && i <= r[id[n - 1]] ? 1 : 0);
	    		else
	    			dp[n - 2][i] *= (i + 1 <= r[id[n - 1]] ? (r[id[n - 1]] - max(l[id[n - 1]], i + 1) + 1) : 0);	 
	    	}
	    	
	    	mx = r[id[n - 2]];
	    	sum[n - 2][MAXN - 1] = dp[n - 2][MAXN - 1];
	    	ford(i, MAXN - 1)
	    		sum[n - 2][i] = sum[n - 2][i + 1] + dp[n - 2][i];
	    	for (int i = n - 3; i >= 0; i--) {
	    		for (int j = l[id[i]]; j <= r[id[i]]; j++) {
	    			if (_less[i])
						dp[i][j] = dp[i + 1][j];
					else {       				
						dp[i][j] = sum[i + 1][j + 1];
					}
				}
	    		
	    		sum[i][MAXN - 1] = dp[i][MAXN - 1];
	    		ford(j, MAXN - 1)
	    			sum[i][j] = sum[i][j + 1] + dp[i][j];
	    	}
	        /*
	    	forn(i, n) {
	    		cout << id[i];
	    		if (i < n - 1) cout << (_less[i] ? '=' : '<');
	    	}
	    	cout << '\n';
	    	forn(i, 11)
	    		cout << dp[n - 2][i] << ' ';
	    	cout << '\n';
	    	
	    	cout << sum[0][0] << '\n';
	    	*/
	    	ans += sum[0][0];
	    }
		
		if (!next_permutation(id, id + n))
			break;	
	}
	
	cout.precision(40);
	forn(i, n)
		ans *= p[i];
		
	cout << ans;
	
	return 0;
}