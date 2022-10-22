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
typedef pair<ll, ll> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	vector<ll> sum(n + m + 2);
	vector<P> p(n + m);
	for(int i = 0; i < n; i ++) cin >> a[i], p[i] = {100 * i, a[i]};
	for(int i = 0; i < m; i ++) cin >> b[i], p[i + n] = {b[i], 0};
	p.pb({-2.1e9, 0});
	p.pb({2.1e9, 0});
	sort(all(p));
	ll ans = 0;
	for(int i = 1; i < sz(p); i ++) sum[i] = sum[i - 1] + p[i].se;
	for(int l = 0, r; l < sz(p) - 1; l = r) {
		r = l + 1;
		while(r < sz(p) && p[r].se) r ++;
		ll pl = p[l].fi, pr = p[r].fi;
		int q = l;
		for(int j = l + 1; j < r; j ++) {
			ll d = pr - p[j].fi, ql = max(pl, p[j].fi - d);
			while(q < r && 2ll * p[q].fi <= ql + pl) {
				q ++;
			}
			if(p[j].fi != p[r].fi) chkmx(ans, sum[j] - sum[q - 1]);
		}
	}
	cout << ans << '\n';
	return 0;
}