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
const int maxn = 2e5;
const int inf = 1e9;
int n;
ll a[maxn + 5], m;
ll cnt;
struct Node {
	ll x, cnt, d;
	friend bool operator < (Node x, Node y) {
		return x.d < y.d;
	}
};
ll calc(ll x, ll cnt) {
	ll r = x / cnt, c = x % cnt;
	return r * r * (cnt - c) + (r + 1) * (r + 1) * c;
}

int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	cin >> m;
	priority_queue<Node> q;
	ll cur = 0;
	rep(i, 1, n) q.push({a[i] - a[i - 1], 1, calc(a[i] - a[i - 1], 1) - calc(a[i] - a[i - 1], 2)}), cur += calc(a[i] - a[i - 1], 1);
	ll sum = 0;
	while(cur > m) {
		Node u = q.top(); q.pop();
		if(!u.d) {
			return 0;
		}
//		ll l = u.cnt + 1, r = u.x, ans = -1;
//		while(l <= r) {
//			ll mid = l + r >> 1;
//			if(calc(u.x, mid) - calc(u.x, u.cnt) == -u.d * (mid - u.cnt)) ans = mid, l = mid + 1;
//			else r = mid - 1;
//		}
		ll x = u.cnt == u.x / (u.x / u.cnt) ? u.x / (u.x / (u.cnt)) + 1 : u.x / (u.x / u.cnt);
//		if(ans != x) {
//			cout << ans << ' ' << x << ' ' << u.x << ' ' << u.cnt << ' ' << u.x / (u.x / u.cnt) << '\n';;
//			exit(0);
//		}
//		assert(ans == x);
		ll ans = x;
//		cerr << ans << ' ' << u.x / (u.x / u.cnt) << '\n';
		ll t = (cur - m + u.d - 1) / u.d;
		if(t <= ans - u.cnt) {
			sum += t;
			break;
		}
		cur -= (ans - u.cnt) * u.d;
		sum += ans - u.cnt;
		q.push({u.x, ans, calc(u.x, ans) - calc(u.x, ans + 1)});
	}
	cout << sum << '\n';
	return 0;
}