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
template<int T> using A = array<int, T>;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 6000;
struct Node {
	int x, y;
}a[maxn + 5];
int n, cnt[2][2];
int main() {
// 	freopen("in.txt", "r", stdin);
	n = read();
	rep(i, 1, n) a[i].x = read() / 2, a[i].y = read() / 2;
	ll ans = 0;
	rep(i, 1, n) {
		cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = 0; 
		rep(j, 1, n) if(j != i) {
			cnt[a[j].x + a[i].x & 1][a[j].y + a[i].y & 1] ++;
		}
		ans += 1ll * cnt[0][0] * (cnt[0][0] - 1) / 2;
		ans += 1ll * cnt[1][1] * (cnt[1][1] - 1) / 2;
		ans += 1ll * cnt[0][1] * (cnt[0][1] - 1) / 2;
		ans += 1ll * cnt[1][0] * (cnt[1][0] - 1) / 2;
		
		ans += 1ll * cnt[0][0] * cnt[1][0];
		ans += 1ll * cnt[0][0] * cnt[0][1];
		ans += 1ll * cnt[0][0] * cnt[1][1];
//		cout << ans << '\n';
//		cout << cnt[0][0] << ' ' << cnt[0][1] << ' ' << cnt[1][0] << ' ' << cnt[1][1] << '\n';
	}
	cout << ans / 3 << '\n';
	return 0;
}
//sigma i,j,k gcd(a[i], a[j]) + gcd(a[i], a[k]) + gcd(a[k], a[j]) % 4 == 0;