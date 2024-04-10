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
const int maxn = 2e5;
const int maxm = 2e6;
int n, a[maxn + 5], b[maxn + 5], m[maxn + 5], l[maxn + 5], r[maxn + 5];
A<2> ret[maxn + 5];
vector<int> p[maxm + 5];
int solve(vector<int> &s) {
	vector<P> t;
	map<int, int> mp;
	for(auto i : s) {
		l[i] = max(0, a[i] - m[i]);
		r[i] = a[i] - max(0, m[i] - b[i]);
		if(!mp.count(r[i])) mp[r[i]] = l[i];
		else chkmx(mp[r[i]], l[i]);
	}
	for(auto x : mp) t.push_back({x.se, x.fi});
	int res = 0, lst = -1; mp.clear();
	for(auto x : t) {
		if(x.fi > lst) res ++, lst = x.se;
		mp[x.se] = lst;
	}
	for(auto i : s) {
		ret[i] = {a[i] - mp[r[i]], m[i] - a[i] + mp[r[i]]};
	}
	s.clear();
	return res;
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read();
		rep(i, 1, n) a[i] = read(), b[i] = read(), m[i] = read(), p[a[i] + b[i] - m[i]].push_back(i);
		int ans = 0;
		rep(i, 1, n) if(i == p[a[i] + b[i] - m[i]].back()) ans += solve(p[a[i] + b[i] - m[i]]);
		cout << ans << '\n';
		rep(i, 1, n) cout << ret[i][0] << ' ' << ret[i][1] << '\n';
	}
	return 0;
}