/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 1e5;
int T, n, vis[maxn + 5];
char s[maxn + 5], t[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --) {
		cin >> n >> s + 1 >> t + 1;
		int ans = 0;
		rep(i, 1, n) vis[i] = 0;
		rep(i, 1, n) if(s[i] == '1' && t[i] == '1') {
			if(i > 1 && s[i - 1] == '0' && t[i - 1] == '0' && !vis[i - 1]) {
				vis[i - 1] = 1;
			}
			else if(i < n && s[i + 1] == '0' && t[i + 1] == '0') {
				vis[i + 1] = 1;
			}
		}
		rep(i, 1, n) ans += 2 * (s[i] == '1' && t[i] == '0' || s[i] == '0' && t[i] == '1');
		rep(i, 1, n) ans += s[i] == '0' && t[i] == '0';
		cout << ans + count(vis + 1, vis + n + 1, 1) << '\n';
	}
	return 0;
}