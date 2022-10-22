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
const int maxn = 1e5;
const int maxm = 200;
const int mod = 998244353;
int n, a[maxn + 5], f[maxn + 5][maxm + 5][2], g[maxn + 5][maxm + 5][2];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
inline void upd(int &a, int b) {a = add(a, b);}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	f[0][0][1] = 1;
	rep(i, 0, maxm) g[0][i][1] = 1;
	rep(i, 1, n) {
		if(a[i] != -1) {
			rep(j, 0, a[i]) {
				upd(f[i][a[i]][j >= a[i]], f[i - 1][j][0]);
			}
			rep(j, 0, maxm) {
				upd(f[i][a[i]][j >= a[i]], f[i - 1][j][1]);
			}
		}
		else {
			rep(j, 1, maxm) {
				f[i][j][0] = add(g[i - 1][j - 1][0], g[i - 1][j - 1][1]);
				f[i][j][1] = add(f[i - 1][j][0], sub(g[i - 1][maxm][1], g[i - 1][j - 1][1]));
			}
		}
		rep(j, 1, maxm) g[i][j][0] = add(g[i][j - 1][0], f[i][j][0]), g[i][j][1] = add(g[i][j - 1][1], f[i][j][1]);
	}
	cout << g[n][maxm][1] << '\n';
	return 0;
}