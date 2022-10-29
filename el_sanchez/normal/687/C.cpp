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
const int MAXN = 555;

int n, k;
int a[MAXN];
int dp[MAXN][MAXN];
bool ok[MAXN];
vi ans;

int main() {
	
	cin >> n >> k;
	forn(i, n)
		cin >> a[i];

	/*
	ok[0] = ok[k] = 1;
		
	dp[0][0][0] = dp[0][0][a[0]] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++)
			dp[0][i][j] = dp[0][i - 1][j];
		for (int j = 0; j <= k - a[i]; j++)
			dp[0][i][j + a[i]] |= dp[0][i - 1][j];
	}
	
	dp[1][n - 1][k] = 1;
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= k; j++)
			dp[1][i][j] = dp[1][i + 1][j];
		for (int j = a[i + 1]; j <= k; j++)
			dp[1][i][j - a[i + 1]] |= dp[1][i + 1][j];
	}
	
	forn(i, MAXN)
		forn(j, MAXN)
			if (dp[0][i][j] && dp[1][i][j])
				ok[j] = 1;
	*/
	dp[0][0] = 1;
	forn(i, n) {
		for (int S1 = k; S1 >= 0; S1--)
			for (int S2 = k; S2 >= 0; S2--) {
				if (S1 >= a[i] && dp[S1 - a[i]][S2])
					dp[S1][S2] = 1;
				if (S2 >= a[i] && dp[S1][S2 - a[i]])
					dp[S1][S2] = 1;
			}				
	}
	
	forn(i, k + 1)
		forn(j, k + 1)
			if (dp[i][j] && i + j == k)
				ok[i] = ok[j] = 1;
				
	forn(i, k + 1)
		if (ok[i])
			ans.pb(i);
			
	cout << ans.size() << '\n';
	for (auto v: ans)
		cout << v << ' ';
	cout << '\n';
	
	return 0;
}