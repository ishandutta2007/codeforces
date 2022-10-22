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
const int maxn = 1e6;
int n, c, a[maxn + 5], use[maxn + 5], pre[maxn + 5], nw[maxn + 5];
vector<int> d[maxn + 5];
void init() {
	rep(i, 1, maxn) {
		rep(j, 1, maxn / i) d[i * j].pb(i);
	}
}
bool chk(int l, int r) {
	if(l < 0 || r < 0) return 0;
	return pre[r] - pre[l - 1] != 0;
}
int main() {
// 	freopen("in.txt", "r", stdin);
	init();
	for(int T = read(); T; T --) {
		n = read(), c = read();
		rep(i, 1, c) use[i] = 0;
		rep(i, 1, n) use[a[i] = read()] = 1;
		rep(i, 1, c) pre[i] = pre[i - 1] + use[i];
		int flg = 1;
		int cur = 0;
		rep(i, 0, c) nw[i] = -2; 
		rep(i, 1, c) {
			for(auto x : d[i]) {
				if(!use[i / x]) cur -= chk(nw[i / x + 1] + 1, nw[i / x]); 
				if(!use[i / x - 1]) cur -= chk(nw[i / x] + 1, nw[i / x - 1]);
				nw[i / x] = x;
				if(!use[i / x]) cur += chk(nw[i / x + 1] + 1, nw[i / x]); 
//				cout << i << "-->" << x << ' ' << cur << '\n';
				if(!use[i / x - 1]) cur += chk(nw[i / x] + 1, nw[i / x - 1]);
//				cout << i << "-->" << x << ' ' << cur << ' ' << nw[i / x] << ' ' << nw[i / x + 1] << '\n';
			}
//			cout << i << ' ' << cur << "--\n";
//			rep(j, 1, i) {
//				cout << nw[j] << " \n"[j == i];
//			}
			if(cur && use[i]) {
				flg = 0;
				break;
			}
		}
		puts(flg ? "Yes" : "No");
	}
	return 0;
}