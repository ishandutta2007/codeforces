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
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 2e5;
int n, m, a[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read();
		rep(i, 1, n) a[i] = read();
		int ans = 0, cur = 0;
		rep(i, 1, n - 1) {
			if(a[i] != a[i + 1]) {
				int nw = i + 1, cnt = 1 + cur;
				while(nw <= n) {
					int nxt = lower_bound(a + 1, a + n + 1, 2 * a[nw] - a[i]) - a;
					if(nxt == n + 1) break;
					nw = nxt;
					cnt ++;
				}
				chkmx(ans, cnt), cur = 0;
			}
			else cur ++;
		}
		chkmx(ans, cur);
		cout << n - 1 - ans << '\n';
	}
	return 0;
}