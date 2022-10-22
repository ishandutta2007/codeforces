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
int n, k, a[maxn + 5], cnt[maxn + 5];
int main() {
// 	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read(), k = read();
		rep(i, 1, n) cnt[i] = 0;
		rep(i, 1, n) cnt[a[i] = read()] ++;
		rep(i, 1, n) cnt[i] += cnt[i - 1];
		int ans = inf, x, y;
		rep(i, 0, n - 1) {
			int p = lower_bound(cnt + 1, cnt + n + 1, (n + 2 * cnt[i] + k + 1) / 2) - cnt;
			if(p != n + 1 && chkmn(ans, p - i)) {x = i + 1, y = p;}
		}
		rep(i, 1, n) a[i] = x <= a[i] && a[i] <= y ? 1 : -1;
		rep(i, 1, n) a[i] += a[i - 1];
		int cur = 1, lst = 0;
		cout << x << ' ' << y << '\n';
		vector<int> p;
		rep(i, 1, n) {
			if(a[i] == cur) {
				p.pb(i), cur ++;
			}
		}
		rep(i, 0, k - 2) cout << lst + 1 << ' ' << p[i] << '\n', lst = p[i];
		cout << lst + 1 << ' ' << n << '\n';
	}
	return 0;
}