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
const ll inf = 1e18;
const int maxn = 2e5;
int n, k, len[maxn + 5], son[maxn + 5], ans[maxn + 5];
vector<int> G[maxn + 5], s;
void dfs(int u, int par) {
	for(auto v : G[u]) if(v != par) {
		dfs(v, u);
		if(chkmx(len[u], len[v] + 1)) son[u] = v;
	}
	for(auto v : G[u]) if(v != par && v != son[u]) s.pb(len[v] + 1);
}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), k = read();
	rep(i, 2, n) {
		int u = read(), v = read();
		G[u].pb(v), G[v].pb(u);
	}
	dfs(1, 1);
	s.pb(len[1] + 1);
	sort(all(s)), reverse(all(s));
	rep(i, 1, sz(s)) {
		ans[i] = ans[i - 1] + s[i - 1];
	}
	rep(i, sz(s) + 1, n) ans[i] = ans[i - 1];
	ll mx = -inf;
	rep(i, 0, k) {
		int all = n - i, mxb = n - ans[i];
		if(i - mxb < 0) {
			int mid = all + i >> 1;  
			if(mid <= mxb) chkmx(mx, 1ll * (all - mid) * (i - mid));
			else chkmx(mx, 1ll * (all - mxb) * (i - mxb));
		}
		else chkmx(mx, 1ll * (i - mxb) * (all - mxb));
	}
	cout << mx << '\n';
	return 0;
}