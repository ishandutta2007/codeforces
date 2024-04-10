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
const int maxn = 1e5;
const int maxlg = 18;
const ll inf = 1e18;
int n, tot, mu[maxn + 5], pri[maxn + 5], vis[maxn + 5];
ll f[maxlg + 5][maxn + 5], g[maxn + 5];
void init() {
	mu[1] = 1;
	rep(i, 2, maxn) {
		if(!vis[i]) mu[pri[++tot] = i] = -1;
		for(int j = 1; j <= tot && pri[j] * i <= maxn; j ++) {
			vis[pri[j] * i] = 1;
			if(i % pri[j] == 0) break;
			mu[i * pri[j]] = -mu[i];
		}
	}
	rep(i, 1, maxn) mu[i] += mu[i - 1];
	rep(i, 1, maxn) {
		for(int l = 1, r; l <= i; l = r + 1) {
		    int t = i / l;
			r = i / t;
			g[i] += 1ll * (mu[r] - mu[l - 1]) * t * (t + 1) / 2;
		}
	}
}
ll calc(int ql, int qr) {
	if(ql > qr) return 0;
	ll ans = 0;
	for(int l = ql, r; l <= qr; l = r + 1) {
		r = qr / (qr / l);
		ans += (r - l + 1) * g[qr / l];
	}
	return ans;
}
int main() {
	//freopen("in.txt", "r", stdin);
	init(); 
	rep(i, 1, maxn) f[0][i] = inf; 
	rep(i, 1, maxlg) {
		function<void(int, int, int, int)> solve = [&] (int l, int r, int ql, int qr) {
			if(l > r) return ;
			int mid = l + r >> 1, p = ql;
			ll cur = calc(ql, mid);
			f[i][mid] = inf;
			rep(j, ql, min(mid, qr)) {
				if(chkmn(f[i][mid], f[i - 1][j - 1] + cur)) p = j;
				cur -= g[mid / j];
			}
			solve(l, mid - 1, ql, p), solve(mid + 1, r, p, qr);
		};
		solve(1, maxn, 1, maxn);
	}
	for(int T = read(); T; T --) {
		int n = read(), k = read();
		if(k <= maxlg) cout << f[k][n] << '\n';
		else cout << n << '\n';
	}
	return 0;
}