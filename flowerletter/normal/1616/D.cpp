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
mt19937_64 hua(time(0));
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int inf = 1e9;
const int maxn = 1e5;
int n, x, a[maxn + 5], f[maxn + 5][4];
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read();
		rep(i, 1, n) a[i] = read();
		x = read();
		rep(i, 1, n) a[i] -= x;
		rep(i, 1, n) {
			rep(s, 0, 3) f[i][s] = -inf;
			if(i >= 3 && a[i] + a[i - 1] + a[i - 2] >= 0 && a[i] + a[i - 1] >= 0) {
				chkmx(f[i][3], f[i - 1][3] + 1);
			}
			if(i >= 2 && a[i] + a[i - 1] >= 0) {
				chkmx(f[i][3], f[i - 1][1] + 1);
			}
			chkmx(f[i][1], f[i - 1][0] + 1);
			chkmx(f[i][1], f[i - 1][2] + 1);
			
			chkmx(f[i][0], f[i - 1][0]);
			chkmx(f[i][0], f[i - 1][2]);
			
			chkmx(f[i][2], f[i - 1][1]);
			chkmx(f[i][2], f[i - 1][3]);
		}
		cout << max({f[n][0], f[n][1], f[n][2], f[n][3]}) << '\n';
	}
	return 0;
}