#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
const int maxn = 1e5;
int T, n, m, u, v, w, vis[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --) {
		cin >> n >> m;
		rep(i, 1, n) vis[i] = 0;
		rep(i, 1, m) cin >> u >> v >> w, vis[v] = 1;
		int p = min_element(vis + 1, vis + n + 1) - vis;
		rep(i, 1, n) if(i != p) cout << p << ' ' << i << '\n';
	}
	return 0;
}