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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = (int)1e9;
const int MAXN = 80;
const int MAXL = 5;
const int MAXM = 20;
const int MOD = (int)1e9 + 7;

int n;
string s;
int subNum[MAXN][MAXL + 1];
int add[MAXL + 1][MAXL + 3];
int dp[MAXL + 1][2][1 << MAXM];

int main() {

	forn(i, MAXL + 1) {
		forn(j, MAXL + 3) {
			add[i][j] = (i + j) % (MAXL + 1);
		}
	}
	
	while (cin >> n) {
		cin >> s;

		memset(subNum, -1, sizeof(subNum));
		
		for (int i = 0; i < (int)s.size(); i++) {
			for (int len = 1; len <= MAXL && i + len <= (int)s.size(); len++) {
				int cur = 0;
				forn(j, len) {
					cur = (cur * 2 + (s[i + j] - '0'));
				}
				if (cur > 0 && cur <= MAXM && s[i] != '0') {
					subNum[i][len] = cur;	
				}
				//cout << subNum[i][len] << '\n';
			}
		}
		
		memset(dp, 0, sizeof(dp));
		int I = 0;
		
		int ans = 0;
	
		for (int i = 0; i <= n; i++) {
			int nI = (I + MAXL) % (MAXL + 1);	
			forn(k, 2) {
				forn(j, 1 << MAXM) {
					dp[nI][k][j] = 0;	
				}
			}
			    
			//cout << "---\n";
			
			int ok = 1;
			while (ok < (1 << MAXM)) {
				if (dp[I][1][ok] > 0) {
					//cout << i << ' ' << ok << ' ' << dp[I][1][ok] << '\n';
				}
				ans = (ans + dp[I][1][ok]) % MOD;
				ok = ok * 2 + 1;
			}
			
			dp[I][0][0]++;
			if (dp[I][0][0] >= MOD) {
				dp[I][0][0] -= MOD;	
			}
			
			for (int mask = 0; mask < (1 << MAXM); mask++) {
				for (int len = 1; len <= MAXL; len++) {
					if (subNum[i][len] != -1) {
						int nmask = mask | (1 << (subNum[i][len] - 1));
						dp[add[I][len]][1][nmask] += dp[I][0][mask];
						if (dp[add[I][len]][1][nmask] >= MOD) {
							dp[add[I][len]][1][nmask] -= MOD;	
						}
						dp[add[I][len]][1][nmask] += dp[I][1][mask];
						if (dp[add[I][len]][1][nmask] >= MOD) {
							dp[add[I][len]][1][nmask] -= MOD;	
						}
					}
				}
				
				if (s[i] == '0') {
					dp[add[I][1]][0][mask] += dp[I][1][mask];
					if (dp[add[I][1]][0][mask] >= MOD) {
						dp[add[I][1]][0][mask] -= MOD;	
					}	
					
					dp[add[I][1]][0][mask] += dp[I][0][mask];
					if (dp[add[I][1]][0][mask] >= MOD) {
						dp[add[I][1]][0][mask] -= MOD;	
					}
				}
			}
			
			I = (I + 1) % (MAXL + 1);
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}