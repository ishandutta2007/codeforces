#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++)
#define per(i, r, l) for(int i = (r); i >= (l); i --)
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s.size())
#define lb(s) ((s) & -(s))
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
template<int T> using A = array<int, T>;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 400;
const int inf = 1e9;
int n, m, a[maxn + 5][maxn + 5], s[maxn + 5][maxn + 5];
int cnt(int p, int l, int r, int c) {
	return c ? s[r][p] - s[l - 1][p] : r - l + 1 - cnt(p, l, r, 1); 
}
int f(int k, int i, int j) {
	return cnt(k, i + 1, j - 1, 1) + (a[i][k] == 0) + (a[j][k] == 0);
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read(), m = read();
		rep(i, 1, n) {
			static char s[maxn + 5];
			cin >> s + 1;
			rep(j, 1, m) a[i][j] = s[j] - '0';
		}
		rep(i, 1, n) rep(j, 1, m) s[i][j] = s[i - 1][j] + a[i][j];
		int ans = inf;
		rep(i, 1, n) {
			rep(j, i + 4, n) {
				int mn = inf;
				rep(k, 1, m) {
					if(k >= 4) {
						chkmn(mn, cnt(k - 3, i + 1, j - 1, 0) + f(k - 1, i, j) + f(k - 2, i, j));
					}
					chkmn(ans, mn + cnt(k, i + 1, j - 1, 0));
					mn += f(k, i, j);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}