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
const int maxn = 100;
int vis[maxn + 5], ans[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		int n = read(), a = read(), b = read();
		rep(i, 1, n) vis[i] = 0;
		vis[ans[1] = a] = 1, vis[ans[n] = b] = 1; 
		int tot = 2;
		per(i, n, 1) if(!vis[i] && tot <= n / 2) ans[tot ++] = i, vis[i] = 1;
		rep(i, 1, n) if(!vis[i]) ans[tot ++] = i;
		if(*min_element(ans + 1, ans + n / 2 + 1) != a || *max_element(ans + n / 2 +1, ans + n + 1) != b) {
			cout << -1 << '\n';
		}
		else {
			rep(i, 1, n) cout << ans[i] << " \n"[i == n]; 
		}
	} 
	return 0;
}