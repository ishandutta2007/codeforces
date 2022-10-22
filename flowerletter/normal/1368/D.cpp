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
const int lg = 20;
int n, a[maxn + 5], cnt[lg + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	n = read();
	rep(i, 1, n) {
		a[i] = read();
		rep(j, 0, lg) cnt[j] += (a[i] >> j) & 1;
	}
	ll ans = 0;
	rep(i, 1, n) {
		int x = 0;
		rep(j, 0, lg) if(cnt[j]) {
			x |= 1 << j;
			cnt[j] --;
		}
		ans += 1ll * x * x;
	}
	cout << ans << '\n';
	return 0;
}