#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
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
const int maxn = 5e5;
int n, d, ans, vis[maxn + 5];
A<2> a[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), d = read();
	rep(i, 1, n) a[i][0] = read(), a[i][1] = read();
	sort(a + 1, a + n + 1, [&] (A<2> x, A<2> y) {return max(x[0], x[1]) == max(y[0], y[1]) ? min(x[0], x[1]) < min(y[0], y[1]) : max(x[0], x[1]) < max(y[0], y[1]);});
	int sum = 0;
	rep(i, 1, n) {
		if(a[i][0] >= d) sum ++, chkmx(d, a[i][1]);
	}
	cout << sum << '\n';
	return 0;
}