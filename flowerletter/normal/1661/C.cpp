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
const int maxn = 3e5;
int T, n, h[maxn + 5];
ll solve(int x) {
	int mx = *max_element(h + 1, h + n + 1);
	if(mx % 2 != x) mx ++;
	ll cnt1 = 0, cnt2 = 0;
	rep(i, 1, n) if(h[i] % 2 != x) cnt1 ++;
	rep(i, 1, n) cnt2 += (mx - h[i]) / 2;
	if(cnt2 > cnt1) {
		ll x = (cnt2 - cnt1 + 1) / 3;
		cnt1 += 2 * x, cnt2 -= x;
	}
	return cnt1 > cnt2 ? cnt1 * 2 - 1 : cnt2 * 2;
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for(cin >> T; T; T --) {
		cin >> n;
		rep(i, 1, n) cin >> h[i];
		cout << min(solve(0), solve(1)) << '\n';
	}
	return 0;
}