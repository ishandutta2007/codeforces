#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk make_pair
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline ll read() {
	ll x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		ll k = read(), x = read();
		if(x >= k * (k - 1) / 2 + k * (k + 1) / 2) {
			cout << 2 * k - 1 << '\n';
		}
		else if(x >= k * (k + 1) / 2) {
			x -= k * (k - 1) / 2;
			ll l = 0, r = k, ans = -1;
			while(l <= r) {
				ll mid = l + r >> 1;
				if((k + k - mid + 1) * mid / 2 >= x) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			cout << ans + k - 1 << '\n';
		}
		else {
			ll y = sqrt(x * 2);
			while(y * (y + 1) / 2 > x) y --;
			cout << y + (y * (y + 1) / 2 < x) << '\n';
		}
	}
	return 0;
}