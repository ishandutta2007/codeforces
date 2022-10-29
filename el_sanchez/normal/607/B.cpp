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
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 511;

int n;
int a[MAXN];
int dp[MAXN][MAXN];
int nxt[MAXN][MAXN];

int main() {

	cin >> n;
	forn(i, n) {
		cin >> a[i];
		a[i]--;
	}
	
	forn(i, n)
		nxt[n - 1][i] = INF;
	for (int i = n - 2; i >= 0; i--) {
		forn(j, n)
			nxt[i][j] = nxt[i + 1][j];
		nxt[i][a[i + 1]] = i + 1;	
	}
	
	for (int i = 0; i < n; i++)
		dp[i][i] = 1;
	for (int i = 0; i < n - 1; i++)
		dp[i][i + 1] = (a[i] == a[i + 1] ? 1 : 2);
	
	for (int len = 3; len <= n; len++) {
		for (int L = 0; L + len - 1 < n; L++) {
			int R = L + len - 1;
			
			dp[L][R] = dp[L + 1][R] + 1;
			
			int j = nxt[L][a[L]];
			while (j <= R) {
				if (L + 1 == j)
					dp[L][R] = min(dp[L][R], 1 + dp[L + 2][R]);
				else
					dp[L][R] = min(dp[L][R], dp[L + 1][j - 1] + dp[j + 1][R]);
					
				j = nxt[j][a[L]];
			}
		}
	}
	
	cout << dp[0][n - 1] << '\n';
	
	return 0;
}