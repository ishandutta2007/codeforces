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
A<7> chk(A<3> a) {
	A<7> b;
	rep(s, 1, 7) {
		int sum = 0;
		rep(i, 0, 2) if(s >> i & 1) sum += a[i];
		b[s - 1] = sum;
	}
	rep(i, 0, 6) {
	    rep(j, 1, 6) if(b[j - 1] > b[j]) swap(b[j - 1], b[j]);
	}
	return b;
}
int main() {
// 	freopen("in.txt", "r", stdin);f
	for(int T = read(); T; T --) {
		A<7> a;
		rep(i, 0, 6) a[i] = read();
		if(chk({a[0], a[1], a[2]}) == a) cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
		else cout << a[0] << ' ' << a[1] << ' ' << a[3] << '\n';
	}
	return 0;
}