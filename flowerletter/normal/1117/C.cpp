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
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 1e5;
const ll inf = 1e18;
int n, x1, y1, x2, y2, dx, dy;
int prex[maxn + 5], prey[maxn + 5];
char s[maxn + 5];
bool check(ll x) {
	ll s = x / n, r = x % n;
	ll ddx = dx - prex[n] * s - prex[r], ddy = dy - prey[n] * s - prey[r];
	return abs(ddx) + abs(ddy) <= x;
}
int main() {
	x1 = read(), y1 = read(), x2 = read(), y2 = read();
	dx = x2 - x1, dy = y2 - y1;
	if(!dx && !dy) {
		return cout << 0 << '\n', 0;
	}
	n = read(), cin >> s + 1;
	rep(i, 1, n) {
		prex[i] = prex[i - 1] + (s[i] == 'L' ? -1 : (s[i] == 'R' ? 1 : 0));
		prey[i] = prey[i - 1] + (s[i] == 'D' ? -1 : (s[i] == 'U' ? 1 : 0));
	}
	if(prex[n] + prey[n] == - dx - dy) {
		cout << -1 << '\n';
		return 0;
	}
	ll l = 1, r = 1e18, ans = -1;
	while(l <= r) {
		ll mid = l + r >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l= mid + 1;
	}
	cout << ans << '\n';
	return 0;
}