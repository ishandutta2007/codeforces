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
int n, k;
ll b[maxn + 5], c[maxn + 5];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	rep(i, 1, n) cin >> b[i];
	ll cur = 0, cnt = 0, ans = 0;
	per(i, n, 1) {
		ll del = b[i] - cur;
		cnt -= c[i];
		if(del > 0) {
			ll x = min(k, i);
			cnt += (del + x - 1) / x;
			cur += (del + x - 1) / x * x;
			if(i > k) c[i - k] += (del + x - 1) / x;
			ans += (del + x - 1) / x;
		}
		cur -= cnt;
	}
	cout << ans << '\n';
	return 0;
}