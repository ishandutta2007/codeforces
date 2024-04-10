/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fir first
#define sec second
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int maxn = 1e5, inf = 1e9;

int T, n, dp[maxn + 5][4];//00,01,10,11 
char s[maxn + 5];

inline void chmin(int &a,int b) {a = a < b ? a : b;}
inline bool is(int p){return p >= 1 && p <= n;} 
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		rep(i, 0, n) dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = inf;
		dp[0][0] = 0;
		rep(i, 1, n) {
			if(is(i - 2) && is(i - 1) && s[i] == s[i - 2] && s[i] == s[i - 1]) {
				chmin(dp[i][1], dp[i - 1][2] + 1);
				chmin(dp[i][2], dp[i - 1][3]);
				chmin(dp[i][3], dp[i - 1][1] + 1);
				chmin(dp[i][3], dp[i - 1][3] + 1);
			}
			else if(is(i - 2) && s[i] == s[i - 2]) {
				chmin(dp[i][0], dp[i - 1][2]);
				chmin(dp[i][1], dp[i - 1][0] + 1);
				chmin(dp[i][1], dp[i - 1][2] + 1);
				chmin(dp[i][2], dp[i - 1][3]);
				chmin(dp[i][3], dp[i - 1][1] + 1);
				chmin(dp[i][3], dp[i - 1][3] + 1); 
			}
			else if(is(i - 1) && s[i] == s[i - 1]) {
				chmin(dp[i][1], dp[i - 1][0] + 1);
				chmin(dp[i][1], dp[i - 1][2] + 1);
				chmin(dp[i][2], dp[i - 1][1]);
				chmin(dp[i][2], dp[i - 1][3]);
				chmin(dp[i][3], dp[i - 1][1] + 1);
				chmin(dp[i][3], dp[i - 1][3] + 1);
			}
			else {
				chmin(dp[i][0], dp[i - 1][0]);
				chmin(dp[i][0], dp[i - 1][2]);
				chmin(dp[i][1], dp[i - 1][0] + 1);
				chmin(dp[i][1], dp[i - 1][2] + 1);
				chmin(dp[i][2], dp[i - 1][1]);
				chmin(dp[i][2], dp[i - 1][3]);
				chmin(dp[i][3], dp[i - 1][1] + 1);
				chmin(dp[i][3], dp[i - 1][3] + 1);
			}
		}
		printf("%d\n", min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}));
	}
	return 0;
}