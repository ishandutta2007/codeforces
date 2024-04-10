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
const ll inf = 1e16;
int T, n, m;
ll p[maxn + 5], q[maxn + 5];
ll dp[maxn + 5][2];
struct Range {
	ll l, r;
}a[maxn + 5];
vector<Range> s;
int main() {
//	freopen("in.txt", "r", stdin);
	int cnt = 0;
	for(cin >> T; T; T --) {
		s.clear();
		cin >> n >> m;
		rep(i, 1, n) cin >> p[i];
		rep(i, 1, m) cin >> a[i].l >> a[i].r;
		sort(p + 1, p + n + 1);
		sort(a + 1, a + m + 1, [&] (Range x, Range y) {return x.r == y.r ? x.l > y.l : x.r < y.r;});
		ll nw = 1, mx = -inf;
		s.push_back({-inf, -inf});
		rep(i, 1, m) {
			while(nw <= n && p[nw] <= a[i].l) q[nw] = sz(s), nw ++;
			if(nw <= n && a[i].l <= p[nw] && p[nw] <= a[i].r || a[i].l <= mx) continue;
			s.push_back(a[i]); mx = a[i].l; 
		}
		while(nw <= n) q[nw] = sz(s), nw ++;
		s.push_back({inf, inf});
		p[0] = -inf; q[0] = 1;
		rep(i, 1, n) {
			if(q[i] == q[i - 1]) {
				dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
				dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
				continue;
			}
			dp[i][0] = dp[i][1] = inf;
			rep(j, q[i - 1] + 1, q[i] - 1) {
				chkmn(dp[i][0], dp[i - 1][0] + 2 * (s[j - 1].l - p[i - 1]) + p[i] - s[j].r);
			}
			chkmn(dp[i][0], dp[i - 1][0] + (s[q[i] - 1].l - p[i - 1]) * 2);
			chkmn(dp[i][0], dp[i - 1][0] + p[i] - s[q[i - 1]].r);
			rep(j, q[i - 1] + 1, q[i] - 1) {
				chkmn(dp[i][0], dp[i - 1][1] + s[j - 1].l - p[i - 1] + p[i] - s[j].r);
			}
			chkmn(dp[i][0], dp[i - 1][1] + s[q[i] - 1].l - p[i - 1]);
			chkmn(dp[i][0], dp[i - 1][1] + p[i] - s[q[i - 1]].r);
			rep(j, q[i - 1] + 1, q[i] - 1) {
				chkmn(dp[i][1], dp[i - 1][0] + 2 * (s[j - 1].l - p[i - 1]) + 2 * (p[i] - s[j].r));
			}
			chkmn(dp[i][1], dp[i - 1][0] + (s[q[i] - 1].l - p[i - 1]) * 2);
			chkmn(dp[i][1], dp[i - 1][0] + (p[i] - s[q[i - 1]].r) * 2);
			rep(j, q[i - 1] + 1, q[i] - 1) {
				chkmn(dp[i][1], dp[i - 1][1] + s[j - 1].l - p[i - 1] + 2 * (p[i] - s[j].r));
			}
			chkmn(dp[i][1], dp[i - 1][1] + s[q[i] - 1].l - p[i - 1]);
			chkmn(dp[i][1], dp[i - 1][1] + 2 * (p[i] - s[q[i - 1]].r));
			//assert(dp[i][0] >= 0), assert(dp[i][1] >= 0);
			if(dp[i][0] < 0 || dp[i][1] < 0) {
				cout << p[i] << "00" << s[q[i]].l << "00" << s[q[i]].r << "00" << s[q[i] - 1].l << "00" << s[q[i] - 1].r << '\n';
				//cout << q[i] << "00" << sz(s) << '\n';
			}
		}
		cout << min(dp[n][0] + 2 * max(0ll, (s[sz(s) - 2].l - p[n])), dp[n][1] + max(0ll, (s[sz(s) - 2].l - p[n]))) << '\n';
	}
	return 0;
}