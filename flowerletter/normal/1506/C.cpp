/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 20;
int T, n, m, ans, dp[maxn + 5][maxn + 5];
char s[maxn + 5], t[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	for(scanf("%d", &T); T; T--) {
		scanf("%s%s", s + 1, t + 1);
		n = strlen(s + 1), m = strlen(t + 1), ans = 0;
		rep(i, 1, n) rep(j, 1, m) {
			dp[i][j] = 0;
			if(s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			chkmx(ans, dp[i][j]);
		}
		printf("%d\n", n + m - 2 * ans);
	}
	return 0;
}