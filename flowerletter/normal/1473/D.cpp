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

const int maxn = 2e5;

int T, n, m, l, r, sum[maxn + 5], lg[maxn + 5];
int mx[18][maxn + 5], mn[18][maxn + 5];
char s[maxn + 5];
int qrymx(int l, int r) {
	int k = lg[r - l + 1];
	return max(mx[k][l], mx[k][r - (1 << k) + 1]);
}
int qrymn(int l, int r) {
	int k = lg[r - l + 1];
	return min(mn[k][l], mn[k][r - (1 << k) + 1]);
}
int main() {
//	freopen("in.txt", "r", stdin);
	rep(i, 2, 2e5 + 2) lg[i] = lg[i >> 1] + 1;
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d%s", &n, &m, s + 1);
		rep(i, 1, n) mx[0][i] = mn[0][i] = sum[i] = sum[i - 1] + (s[i] == '+' ? 1 : -1);
		mx[0][0] = mn[0][0] = 0, mx[0][n + 1] = mn[0][n + 1] = sum[n];
		rep(i, 1, 17) rep(j, 0, n - (1 << i) + 2) mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << i - 1)]);
		rep(i, 1, 17) rep(j, 0, n - (1 << i) + 2) mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << i - 1)]);
		rep(i, 1, m) {	
			scanf("%d%d", &l, &r);
			int mx1 = qrymx(0, l - 1), mx2 = qrymx(r + 1, n + 1) - (sum[r] - sum[l - 1]);
			int mn1 = qrymn(0, l - 1), mn2 = qrymn(r + 1, n + 1) - (sum[r] - sum[l - 1]);
			printf("%d\n", max(mx1, mx2) - min(mn1, mn2) + 1);
		}
	}
	return 0;
}