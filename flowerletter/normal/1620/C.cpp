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
mt19937_64 hua(time(0));
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline ll read() {
	ll x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int inf = 1e9;
const int maxn = 2000;
int n, k, f[maxn + 5];
ll x;
char s[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		n = read(), k = read(), x = read(), x --;
		cin >> s + 1;
		for(int r = n, l; r >= 1; r = l - 1) {
			if(s[l = r] == 'a') continue;
			while(l > 1 && s[l - 1] == '*') f[l --] = 0;
			f[l] = x % ((r - l + 1) * k + 1);
			x /= (r - l + 1) * k + 1;
		}
		rep(i, 1, n) {
			if(s[i] == 'a') putchar('a');
			else rep(j, 1, f[i]) putchar('b');
		}
		putchar('\n');
	}
	return 0;
}