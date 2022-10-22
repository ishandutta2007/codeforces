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
const int maxn = 2e5;
const int inf = 1e9;
int n, f[maxn + 5][4];
char str[maxn + 5];
bool chk(int a, int b, int c) {
	if(a == c) return b == !a;
	else return 1;
}
int solve() {
	rep(s, 0, 3) f[1][s] = inf; 
	f[1][str[n] == 'R' | (str[1] == 'R') << 1] = 0;
	rep(i, 2, n - 1) rep(s, 0, 3) f[i][s] = inf;
	rep(i, 2, n - 1) {
		rep(s, 0, 3) {
			rep(d, 0, 1) if(chk(s & 1, s >> 1 & 1, d)) {
				int t = s >> 1 | d << 1;
				chkmn(f[i][t], f[i - 1][s] + (d != (str[i] == 'R')));
			}
		}
	}
	int ans = inf;
	rep(s, 0, 3) if(chk(s & 1, s >> 1 & 1, str[n] == 'R') && chk(s >> 1 & 1, str[n] == 'R', str[1] == 'R')) {
		chkmn(ans, f[n - 1][s]);
	}
	return ans;
}
int main() {
	//freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read();
		cin >> (str + 1);
		int ans1 = solve();
		str[1] = 'L' + 'R' - str[1];
		int ans2 = solve() + 1;
		str[n] = 'L' + 'R' - str[n];
		int ans3 = solve() + 2;
		str[1] = 'L' + 'R' - str[1];
		int ans4 = solve() + 1;
		cout << min({ans1, ans2, ans3, ans4}) << '\n';
	}
	 
	return 0;
}