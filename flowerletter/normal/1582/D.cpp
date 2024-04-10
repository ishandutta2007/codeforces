#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
const int maxn = 1e5;
int T, n, a[maxn + 5]; 
void exgcd(ll a, ll b, ll &x, ll &y) {
	if(!b) return x = 1, y = 0, void();
	exgcd(b, a % b, y, x), y -= a / b * x;
}
int main() {
//	freopen("in.txt", "r", stdin);
	for(cin >> T; T; T --) {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		if(n & 1) {
			ll b = __gcd(a[2], a[3]), x, y;
			exgcd(a[2], a[3], x, y); 
			x = x * a[1], y = y * a[1];
			ll t = a[2] < a[3] ? x / a[3] : -y / a[2];
			x -= t * a[3], y += t * a[2];
			while(!x || !y) x += a[3], y -= a[2];
			cout << -b << ' ' << x << ' ' << y << ' ';
			for(int i = 4; i <= n; i += 2) {
				int b = __gcd(a[i], a[i + 1]);
				cout << -a[i + 1] / b << ' ' << a[i] / b << ' ';
			}
			cout << '\n';
		}
		else {
			for(int i = 1; i <= n; i += 2) {
				int b = __gcd(a[i], a[i + 1]);
				cout << -a[i + 1] / b << ' ' << a[i] / b << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}