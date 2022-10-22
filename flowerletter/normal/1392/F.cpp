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
typedef __int128 u128;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
template<int T> using A = array<int, T>;

inline ll read() {
	ll x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 1e6;
const ll inf = 1e18;
int n;
ll h[maxn + 5], a[maxn + 5], sum; 
int main() {
//	freopen("in.txt", "r", stdin);
	n = read();
	rep(i, 1, n) h[i] = read(), sum += h[i];
	ll l = 0, r = 1e12, ans = -1;
	while(l <= r) {
		ll mid = l + r >> 1;
		if((u128)n * (2 * mid + n - 1) / 2 > sum) r = mid - 1;
		else ans = mid, l = mid + 1;
	}
	ll ret = sum - n * (2 * ans + n - 1) / 2;
	rep(i, 1, n) a[i] = ans + i - 1 + (i <= ret);
	rep(i, 1, n) {
		cout << a[i] << " \n"[i == n];
	}
	return 0;
}