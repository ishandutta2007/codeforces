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
const int maxn = 300;
int T, n, m, mp[maxn + 5][maxn + 5], id[maxn * maxn + 5];
P a[maxn * maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --) {
		cin >> n >> m;
		rep(i, 1, n) rep(j, 1, m) mp[i][j] = 0;
		rep(i, 1, n * m) cin >> a[i].fi, a[i].se = i;
		sort(a + 1, a + n * m + 1);
		rep(i, 1, n * m) id[a[i].se] = i;
		int ans = 0;
		rep(i, 1, n * m) {
			int x = (id[i] - 1) / m + 1, y = (id[i] - 1) % m + 1;
			rep(j, 1, y - 1) if(mp[x][j] && mp[x][j] < a[id[i]].fi) ans ++;
			mp[x][y] = a[id[i]].fi;
		}
		cout << ans << '\n';
	}
	return 0;
}