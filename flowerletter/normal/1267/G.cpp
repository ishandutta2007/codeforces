/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}

const int maxn = 100;
const int maxw = 10000;
int n, p, a[maxn + 5];
double c[maxn + 5][maxn + 5], dp[maxn + 5][maxw + 5], ans;
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &p);
	rep(i, 1, n) scanf("%d", &a[i]);
	c[0][0] = 1, dp[0][0] = 1;
	rep(i, 1, n) c[i][0] = 1;
	rep(i, 1, n) rep(j, 1, i) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	rep(i, 1, n) per(j, i, 1) rep(k, a[i], maxw) dp[j][k] += dp[j - 1][k - a[i]];
	rep(i, 0, n - 1) rep(j, 0, maxw) ans += 1.0 * dp[n - i][j] / c[n][i] * min(1.0 * (2 * n - i) * p / 2 / (n - i), 1.0 * j / (n - i));
	printf("%.10lf\n", ans);
	return 0;
}