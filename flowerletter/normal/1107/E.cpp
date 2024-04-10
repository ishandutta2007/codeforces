#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk make_pair
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 100;
const ll inf = 1e18;
int n, a[maxn + 5];
ll f[maxn + 5][maxn + 5], g[maxn + 5][maxn + 5][2];
char s[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	n = read(), cin >> s + 1;
	rep(i, 1, n) a[i] = read(), s[i] -= '0'; 
	per(l, n, 1) {
		rep(k, 1, n) g[l - 1][k][0] = g[l - 1][k][1] = -inf;
		rep(r, l, n) {
			rep(k, 1, n) {
				g[r][k][0] = g[r][k][1] = -inf;
				rep(t, l, r - 1) chkmx(g[r][k][0], g[t][k][0] + f[t + 1][r]), chkmx(g[r][k][1], g[t][k][1] + f[t + 1][r]);
				chkmx(g[r][k][s[r]], g[r - 1][k - 1][s[r]]);
				chkmx(f[l][r], g[r][k][0] + a[k]), chkmx(f[l][r], g[r][k][1] + a[k]); 
			}
		}
	}
	cout << f[1][n] << '\n';
	return 0;
}