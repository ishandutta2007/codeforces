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

inline ll read() {
	ll x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
string s = "codeforces";
int main() {
	//freopen("in.txt", "r", stdin);
	ll n = read();
	ll x = pow(n, 0.1), res = pow(x, 10), cnt = 10;
	rep(i, 0, 10) {
		if(res >= n) {cnt = i; break;}
		res /= x, res *= x + 1;
	}
	rep(i, 0, cnt - 1) {
		rep(c, 0, x) cout << s[i];
	}
	rep(i, cnt, 9) rep(c, 1, x) cout << s[i];
	return 0;
}