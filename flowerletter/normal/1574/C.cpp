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
const int maxn = 2e5;
const ll inf = 2e18;
int n, m;
ll a[maxn + 5], x, y, sum;
int main() {
//	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, 1, n) cin >> a[i], sum += a[i];
	sort(a + 1, a + n + 1);
	cin >> m;
	rep(i, 1, m) {
		cin >> x >> y;
		ll ans = inf;
		ll p = lower_bound(a + 1, a + n + 1, x) - a;
		if(p <= n) chkmn(ans, max(0ll, y - sum + a[p]));
		if(p > 1) chkmn(ans, x - a[p - 1] + max(0ll, y - sum + a[p - 1]));
		cout << ans << '\n';
	}
	return 0;
}