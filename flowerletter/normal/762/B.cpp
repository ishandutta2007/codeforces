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
int a, b, c, n;
vector<int> d[2];
int main() {
//	freopen("in.txt", "r", stdin);
	a = read(), b = read(), c = read();
	n = read();
	rep(i, 1, n) {
		int x = read();
		static char s[maxn + 5];
		cin >> s + 1;
		if(s[1] == 'U') {
			d[0].pb(x);
		}
		else {
			d[1].pb(x);
		}
	}
	sort(all(d[0])), sort(all(d[1]));
	ll ret = 0;
	int cnt = 0, p = -1, q = -1;
	rep(i, 0, min(a, sz(d[0])) - 1) ret += d[0][i], cnt ++, p = i;
	rep(i, 0, min(b, sz(d[1])) - 1) ret += d[1][i], cnt ++, q = i;
	rep(i, 1, c) {
		if(p == sz(d[0]) - 1 || q == sz(d[1]) - 1) {
			rep(j, i, c) {
				if(p == sz(d[0]) - 1 && q == sz(d[1]) - 1) break;
				cnt ++; 
				if(p == sz(d[0]) - 1) ret += d[1][q + 1], q ++;
				else ret += d[0][p + 1], p ++;
			}
			break;
		}
		cnt ++;
		if(d[0][p + 1] < d[1][q + 1]) ret += d[0][p + 1], p ++;
		else ret += d[1][q + 1], q ++;
	}
	cout << cnt << ' ' << ret << '\n';
	return 0;
}