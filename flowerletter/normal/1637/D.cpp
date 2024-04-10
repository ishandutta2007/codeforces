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
const int maxn = 100;
const int maxm = 10000;
int n, a[maxn + 5], b[maxn + 5];
bitset<maxm + 5> f, g;
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read();
		ll ans = 0, sum = 0;
		rep(i, 1, n) a[i] = read(), ans += (n - 2) * a[i] * a[i], sum += a[i];
		rep(i, 1, n) b[i] = read(), ans += (n - 2) * b[i] * b[i], sum += b[i];
		f.reset(), g.reset(); 
		f[0] = 1;
		rep(i, 1, n) {
			f = f << a[i] | f << b[i];
		}
		ll mn = sum, id = 0;
		rep(i, 0, sum) if(f[i]) if(chkmn(mn, abs(sum - 2 * i))) id = i; 
		cout << ans + id * id + (sum - id) * (sum - id) << '\n'; 
	}
	return 0;
}