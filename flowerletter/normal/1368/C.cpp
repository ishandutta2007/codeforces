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
int n;
vector<P> ans;
int main() {
//	freopen("in.txt", "r", stdin);
	n = read();
	ans.pb({0, 1}), ans.pb({1, 0}), ans.pb({0, 0}), ans.pb({n + 1, n + 1});
	rep(i, 1, n) {
		ans.pb({i, i});
		ans.pb({i, i + 1});
		ans.pb({i + 1, i});
	}
	cout << sz(ans) << '\n';
	for(auto x : ans) cout << x.fi << ' ' << x.se << '\n'; 
	return 0;
}