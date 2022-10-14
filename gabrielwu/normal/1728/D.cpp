#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define f first
#define s second
#define rand(i, j) uniform_int_distribution<ll>((ll)(i), (ll)(j))(rng)
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for (int i = 0; i < (int)v.size(); i++) {if (i) cout << ", "; cout << v[i]; } return cout << "]";
}
template<typename T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<typename T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


//2 147 483 647 int max
//9 223 372 036 854 775 807 ll max


int main(){
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t;
	forn(ti, t) {
		string s; cin >> s;
		int n = s.size();
		assert(n%2 == 0);

		vector<vector<int>> dp(n, vector<int>(n+1));
		for(int i=n-1; i>=0; i--) {
			for(int j=i; j<=n; j+=2) {
				if(i == j) dp[i][j] = 2;
				else if(i+2 == j) {
					if(s[i] == s[j-1]) dp[i][j] = 2;
					else dp[i][j] = 1;
				} else {
					int best = 2;

					{
						int worst = 1;
						if(dp[i+1][j-1] == 2 && s[i] == s[j-1]) {
							worst = 2;
						}
						if(dp[i+2][j] == 2 && s[i] == s[i+1]) {
							worst = 2;
						}
						ckmin(best, worst);
					}
					{
						int worst = 1;
						if(dp[i+1][j-1] == 2 && s[i] == s[j-1]) {
							worst = 2;
						}
						if(dp[i][j-2] == 2 && s[j-2] == s[j-1]) {
							worst = 2;
						}
						ckmin(best, worst);
					}
					dp[i][j] = best;
				}
			}
		}

		if(dp[0][n] == 1) {
			cout << "Alice\n";
		} else {
			cout << "Draw\n";
		}

		// //1 = first player wins, 2 = draw, 3 = second player wins
		// vector<vector<pair<char, int>>> dp(n, vector<pair<char, int>>(n+1));
		// for(int i=n-1; i>=0; i--) {
		// 	for(int j=i; j<=n; j+=1) {
		// 		if(i == j) dp[i][j] = {' ', 2};
		// 		else if(i+1 == j) dp[i][j] = {s[i], 2};
		// 		else if((j-i)%2 == 0) {
		// 			if(s[i] < s[j-1]) {
		// 				if(s[i] < dp[i+1][j].f) {
		// 					dp[i][j] = {' ', 1};
		// 				} else if(s[i] > dp[i+1][j].f) {
		// 					dp[i][j] = {' ', 3};
		// 				} else {
		// 					dp[i][j] = {' ', dp[i+1][j].s};
		// 				}
		// 			} else if(s[i] > s[j-1]) {
		// 				if(s[j-1] < dp[i][j-1].f) {
		// 					dp[i][j] = {' ', 1};
		// 				} else if(s[j-1] > dp[i][j-1].f) {
		// 					dp[i][j] = {' ', 3};
		// 				} else {
		// 					dp[i][j] = {' ', dp[i][j-1].s};
		// 				}
		// 			} else {
		// 				int win = 3;
		// 				if(s[i] < dp[i+1][j].f) ckmin(win, 1);
		// 				else if(s[i] == dp[i+1][j].f) ckmin(win, dp[i+1][j].s);
		// 				if(s[j-1] < dp[i][j-1].f) ckmin(win, 1);
		// 				else if(s[j-1] == dp[i][j-1].f) ckmin(win, dp[i][j-1].s);

		// 				dp[i][j] = {' ', win};
		// 			}
		// 		} else {
		// 			if(s[i] < s[j-1]) {
		// 				dp[i][j] = {s[i], dp[i+1][j].s};
		// 			} else if(s[i] > s[j-1]) {
		// 				dp[i][j] = {s[j-1], dp[i][j-1].s};
		// 			} else {
		// 				dp[i][j] = {s[i], max(dp[i+1][j].s, dp[i][j-1].s)};
		// 			}
		// 		}
		// 	}
		// }

		// // cout << dp << "\n";

		// if(dp[0][n].s == 1) {
		// 	cout << "Alice\n";
		// } else if(dp[0][n].s == 2) {
		// 	cout << "Draw\n";
		// } else {
		// 	cout << "Bob\n";
		// }
	}
}