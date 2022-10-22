/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 5000;
const int inf = 1e9;
int n, a[maxn + 5], dp[maxn + 5][maxn + 5], mn[maxn + 5][maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 0, n) rep(j, 0, n) dp[i][j] = inf; 
	dp[0][0] = 0;
	rep(i, 1, n) {
		rep(j, 0, n) if(a[j] == 0) {
			if(a[i] == 1 && j) chkmn(dp[i][j], mn[i - 1][j - 1] + abs(i - j));
			else if(a[i] == 0) chkmn(dp[i][j], dp[i - 1][j]);
		}
		mn[i][0] = dp[i][0];
		rep(j, 1, n) mn[i][j] = min(mn[i][j - 1], dp[i][j]);
	}
	int ans = inf;
	rep(i, 0, n) chkmn(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}