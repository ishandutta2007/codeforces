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
const int maxn = 1000;
const ll inf = 1e9;
int n, a[maxn + 5];
ll ans, s[maxn + 5][maxn + 5], mn[maxn + 5][maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	for(int i = 2; i <= n; i += 2) {
		for(int j = i + 1; j <= n; j += 2) {
			s[i][j] = s[i][j - 2] + a[j] - a[j - 1]; 
			mn[i][j] = min(mn[i][j - 2], s[i][j] - a[j]);
		}
	}
	for(int i = 1; i <= n; i += 2) {
		for(int j = i + 1; j <= n; j += 2) {
			ll l1 = max(1ll, - mn[i + 1][j - 1]), r1 = a[i];
			ll l2 = max(1ll, l1 + s[i + 1][j - 1]), r2 = a[j];
			ans += max(0ll, min(r1 - l1 + 1, r2 - l2 + 1));
		}
	}
	cout << ans << '\n';
	return 0;
}