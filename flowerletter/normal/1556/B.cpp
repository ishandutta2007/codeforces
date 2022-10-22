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
const ll inf = 1e18;
int T, n, a[maxn + 5], cnt[2];
ll ans;
int main() {
//	freopen("in.txt", "r", stdin);
	for(cin >> T; T; T--) {
		cin >> n;
		cnt[0] = cnt[1] = ans = 0;
		rep(i, 1, n) cin >> a[i], cnt[a[i] &= 1] ++;
		if(cnt[0] < cnt[1]) {
			swap(cnt[0], cnt[1]);
			rep(i, 1, n) a[i] ^= 1;
		}
		if(cnt[0] - cnt[1] > 1) puts("-1");
		else if(cnt[0] - cnt[1] == 1){
			cnt[0] = 1, cnt[1] = 2;
			rep(i, 1, n) {
				ans += abs(i - cnt[a[i]]);
				cnt[a[i]] += 2;
			}
			cout << ans / 2<< '\n';
		}
		else {
			ll mn = inf;
			cnt[0] = 1, cnt[1] = 2;
			rep(i, 1, n) {
				ans += abs(i - cnt[a[i]]);
				cnt[a[i]] += 2;
			}
			chkmn(mn, ans), ans = 0;
			cnt[0] = 2, cnt[1] = 1;
			rep(i, 1, n) {
				ans += abs(i - cnt[a[i]]);
				cnt[a[i]] += 2;
			}
			chkmn(mn, ans);
			cout << mn / 2 << '\n';
		}
	}
	return 0;
}