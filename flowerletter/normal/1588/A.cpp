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
const int maxn = 100;
int n, a[maxn + 5], b[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read();
		rep(i, 1, n) a[i] = read();
		rep(i, 1, n) b[i] = read();
		sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
		int flag = 1;
		rep(i, 1, n) if(a[i] != b[i] && a[i] != b[i] - 1) flag = 0;
		cout << (flag ? "Yes\n" : "No\n");
	}
	return 0;
}