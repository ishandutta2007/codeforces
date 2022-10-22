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
inline ll read() {
	ll x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
int len, n[20];
int solve(int x, int y) {
	int flag = 0;
	rep(i, 1, len + 2) {
		if(flag && n[i] == x) return i - 2;
		else if(n[i] == y) flag = 1; 
	}
	return 100;
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		ll x = read();
		len = 0;
		while(x) n[++ len] = x % 10, x /= 10;
		cout << min({solve(0, 0), solve(2, 5), solve(5, 0), solve(7, 5)}) << '\n';
	}
	return 0;
}