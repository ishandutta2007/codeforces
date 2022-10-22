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
const int inf = 1e9;
int w, h, k[4], lim[2];
int mn[4], mx[4];
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		lim[1] = read(), lim[0] = read();
		rep(i, 0, 3) {
			k[i] = read();
			mx[i] = -1, mn[i] = inf;
			rep(j, 1, k[i]) {
				int t = read();
				chkmx(mx[i], t);
				chkmn(mn[i], t);
			}
		}
		ll ans = 0;
		rep(i, 0, 3) if(mx[i] != -1){
			int id = i ^ 1;
			if(mx[id] == -1) {
				int id1 = 3 - id, id2 = id1 ^ 1;
				if(i & 1) chkmx(ans, 1ll * (mx[i] - mn[i]) * max(mx[id1], mx[id2]));
				else chkmx(ans, 1ll * (mx[i] - mn[i]) * max(lim[i >> 1] - mn[id1], lim[i >> 1] - mn[id2])); 
			}
			else chkmx(ans, 1ll * (mx[i] - mn[i]) * lim[i >> 1]);
		}
		cout << ans << '\n';
	}
	return 0;
}