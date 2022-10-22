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
const int maxn = 2e5;
const int mod = 1e9 + 7;
const int lg = 30;
int n, a[maxn + 5], cnt[lg + 1], fpw[maxn + 5];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read();
	vector<int> all;
	fpw[0] = 1;
	rep(i, 1, n) {
		a[i] = read();
		int x = a[i], y =0;
		while(x % 2 == 0) x /= 2, y ++; 
		cnt[y] ++;
		fpw[i] = mul(2, fpw[i - 1]);
	}
	int ans = 0, nw = 0;
	rep(i, 0, lg) {
		nw += cnt[i];
		int cnts = cnt[i], cntt = n - nw;
		if(i) {
			int lst = ans;
			if(cnts) ans = add(ans, mul(fpw[cnts - 1] - 1, fpw[cntt]));
		}
		else {
			ans = add(ans, sub(fpw[n], fpw[cntt]));
		}
	}
	cout << ans << '\n';
	return 0;
}