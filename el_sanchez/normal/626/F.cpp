#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9;		
const int MAXN = 210;
const int MAXK = 1010;
const int MOD = (int)1E9 + 7;

int n, k;
int a[MAXN];
ll dp[2][MAXN][MAXK];
ll ans, add;

int main() {        
	
	cin >> n >> k;
	forn(i, n)
		cin >> a[i];
	sort(a, a + n);
	
	int id = 1;
	dp[1][1][0] = 1; //open
	dp[1][0][0] = 1; //open&close
	for (int i = 1; i < n; i++) {
		id ^= 1;
		for (int open = 0; open <= n; open++)
			for (int sum = 0; sum <= k; sum++)
				dp[id][open][sum] = 0;

		//cout << i << '\n';
		
		for (int open = 0; open <= n; open++)
			for (int sum = 0; sum <= k; sum++)
				if (dp[id ^ 1][open][sum]) {
					//cout << open << ' ' << sum << '\n';
					
					add = dp[id ^ 1][open][sum];
					int newSum;
					
					//new: i
					
					newSum = sum + open * (a[i] - a[i - 1]);
					if (newSum <= k) {
						//open new             					
						dp[id][open + 1][newSum] += add;
						dp[id][open + 1][newSum] %= MOD;
						
						//open&close
						dp[id][open][newSum] += add;
						dp[id][open][newSum] %= MOD;

						//include           					
						dp[id][open][newSum] += 1ll * open * add;
						dp[id][open][newSum] %= MOD;         					
						
						//close new
						if (open >= 1) {
							dp[id][open - 1][newSum] += 1ll * open * add;
							dp[id][open - 1][newSum] %= MOD;
						}
                    }
					
					
				}
	}
	
	ans = 0;
	for (int sum = 0; sum <= k; sum++)
		ans = (ans + dp[id][0][sum]) % MOD;	
	
	cout << ans << '\n';
	
	return 0;
}