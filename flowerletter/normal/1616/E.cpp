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
const int maxn = 1e5;
int n;
char s[maxn + 5], t[maxn + 5];
vector<int> p[26];
struct Bit {
	int c[maxn + 5];
	void clear(int n) {
		rep(i, 0, n) c[i] = 0;
	}
	void add(int x) {
		for(; x <= n ; x += lb(x)) c[x] ++;
	}
	int ask(int x) {
		int ans = 0;
		for(; x; x -= lb(x)) ans += c[x];
		return ans;
	}
	int query(int l, int r) {return ask(r) - ask(l - 1);}
}ds;
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read();
		cin >> s + 1 >> t + 1;
		rep(i, 0, 25) p[i].clear();
		per(i, n, 1) p[s[i] - 'a'].pb(i);
		ll ans = inf, cur = 0;
		ds.clear(n);
		rep(i, 1, n) {
			ll mn = inf;
			rep(j, 0, t[i] - 'a' - 1) if(!p[j].empty()) chkmn(mn, (ll) p[j].back());
			if(mn != inf) chkmn(ans, cur + mn - i + ds.query(mn + 1, n));
			if(p[t[i] - 'a'].empty()) break;
			cur += p[t[i] - 'a'].back() - i + ds.query(p[t[i] -'a'].back() + 1, n);
			ds.add(p[t[i] - 'a'].back());
			p[t[i] - 'a'].pop_back();
		}
		cout << (ans == inf ? -1 : ans) << '\n';
	}
	return 0;
}