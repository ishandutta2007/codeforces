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
const int maxn = 3e5;
int n, m, a[maxn + 5], cnt[maxn + 5];
vector<int> st, s;
vector<int> qry[maxn + 5];
vector<int> pos[maxn + 5];
ll val(int i, int j) {return 1ll * (cnt[i] + cnt[j]) * (st[i - 1] + st[j - 1]);}
void solve() {
	n = read(), m = read();
	rep(i, 1, n) st.pb(a[i] = read());
	sort(all(st)), st.erase(unique(all(st)), st.end());
	rep(i, 1, n) cnt[a[i] = lower_bound(all(st), a[i]) - st.begin() + 1] ++;
	rep(i, 1, n) pos[cnt[i]].pb(i);
	rep(i, 1, n) if(!pos[i].empty()) s.push_back(i);
	rep(i, 1, m) {
		int u = read(), v = read();
		if(!binary_search(all(st), u) || !binary_search(all(st), v)) continue;
		u = lower_bound(all(st), u) - st.begin() + 1;
		v = lower_bound(all(st), v) - st.begin() + 1;
		qry[u].pb(v), qry[v].pb(u); 
//		cout << u << ' ' << v << '\n';
	}
	rep(i, 1, n) {
		sort(all(qry[i]));
		sort(all(pos[i]), [&] (int x, int y) {return x < y;});
	}
//	cout << binary_search(all(qry[3]), 1) << '\n';
//	for()
	ll mx = 0;
	rep(i, 1, sz(st)) {
//		cout << i << '\n';
		for(auto x : s) {
			per(j, sz(pos[x]) - 1, 0) {
				if(pos[x][j] != i && !binary_search(all(qry[i]), pos[x][j])) {
//					cout << i << ' ' << pos[x][j] << ' ' << val(pos[x][j], i) << '\n';
					chkmx(mx, val(pos[x][j], i));
					break;
				}
			}
		}
	}
	cout << mx << '\n';
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		rep(i, 1, n) cnt[i] = 0, pos[i].clear(), qry[i].clear();
		st.clear(), s.clear();
		solve();
	}
	return 0;
}