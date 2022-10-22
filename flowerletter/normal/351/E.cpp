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
const int maxn = 2000;
const int inf = 1e9;
int n, ans, a[maxn + 5], last[maxn + 5], b[maxn + 5];
int dp[maxn + 5][maxn + 5], w[maxn + 5][2], cnt[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]), b[i] = a[i] = abs(a[i]);
	sort(b + 1, b + n + 1); int *end = unique(b + 1, b + n + 1);
	rep(i, 1, n) a[i] = lower_bound(b + 1, end, a[i]) - b;
	rep(i, 1, n) {
		rep(j, i + 1, n) w[i][1] += (a[i] > a[j]);
		rep(j, 1, i - 1) w[i][0] += (a[i] > a[j]);
	}
	rep(i, 0, n) rep(j, 0, n) dp[i][j] = inf; 
	dp[0][0] = 0;
	rep(i, 1, n) {
		rep(j, 0, n) {
			if(j) chkmn(dp[i][j], dp[last[a[i]]][j - 1] + w[i][1]);
			chkmn(dp[i][j], dp[last[a[i]]][j] + w[i][0] + j);
		}
		last[a[i]] = i;
	}
	rep(i, 1, n) if(last[i]) {
		int mn = inf;
		rep(j, 0, n) chkmn(mn, dp[last[i]][j]);
		ans += mn;
	}
	printf("%d", ans);
	return 0;
}