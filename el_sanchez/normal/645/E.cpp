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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 2000500;
const int ALPH = 30;
const int MOD = 1E9 + 7;

int n, k, m;
string s;
int prv[MAXN];
int last[ALPH];
int dp[MAXN];

int main() {

	cin >> m >> k;
	cin >> s;
	
	n = s.size();
	memset(last, -1, sizeof(last));
	
	for (int i = 0; i < n; i++) {
		prv[i] = last[s[i] - 'a'];
		last[s[i] - 'a'] = i;	
	}
	
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = (0ll + 2ll * dp[i - 1]) % MOD;
		if (prv[i - 1] != -1)
			dp[i] = (0ll + dp[i] + MOD - dp[prv[i - 1]]) % MOD;	
	}
	
	for (int i = n + 1; i <= n + m; i++) {
		int id = 0;
		forn(j, k)
			if (last[j] < last[id])
				id = j;

		prv[i - 1] = last[id];
		last[id] = i - 1;

		dp[i] = (0ll + 2ll * dp[i - 1]) % MOD;
		if (prv[i - 1] != -1)
			dp[i] = (0ll + dp[i] + MOD - dp[prv[i - 1]]) % MOD;				
	}
	
	cout << dp[n + m] << '\n';
	
	return 0;
}