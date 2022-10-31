#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int N = 5005;
const int INF = 1e9 + 7;

int dp[N][N];
  
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	string s, t;
	cin >> n >> m;
	cin >> s >> t;
	forn(i, n) {
		forn(j, m) {
			if (s[i] == t[j]) {
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 2);
			}
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] - 1);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] - 1);
		}
	}
	int ans = 0;
	forn(i, n + 1) {
		forn(j, m + 1) {
//			cout << i << " " << j << " " << dp[i][j] << '\n';
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
	return 0;
}