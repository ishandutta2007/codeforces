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
const int maxn = 2e5;
const int B = 400;
int n, m, x[maxn + 5], y[maxn + 5], c[maxn + 5];
int s[B + 5][B + 5], vis[maxn + 5];
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), m = read();
	rep(i, 1, n) x[i] = read(), y[i] = read();
	rep(i, 1, m) {
		int opt = read();
		if(opt == 1) {
			int k = read(); vis[k] = i;
			if(x[k] + y[k] <= B) {
				int z = x[k] + y[k], st = (i + x[k]) % z, ed =(i - 1) % z;
				if(st <= ed) {
					rep(i, st, ed) s[z][i] ++;
				}
				else {
					rep(i, st, z - 1) s[z][i] ++;
					rep(i, 0, ed) s[z][i] ++; 
				}
			}
			else {
				for(int j = i + x[k]; j <= m; j += x[k] + y[k]) {
					c[j] ++;
					if(j + y[k] <= m) c[j + y[k]] --;
				}
			}
		}
		else {
			int k = read();
			if(x[k] + y[k] <= B) {
				int z = x[k] + y[k], st = (vis[k] + x[k]) % z, ed = (vis[k] - 1) % z;
				if(st <= ed) {
					rep(i, st, ed) s[z][i] --;
				}
				else {
					rep(i, st, z - 1) s[z][i] --;
					rep(i, 0, ed) s[z][i] --; 
				}
			}
			else {
				int cnt = 0;
				for(int j = vis[k] + x[k]; j <= m; j += x[k] + y[k]) {
					if(j < i) cnt --; 
					else c[j] --;
					if(j + y[k] < i) cnt ++; 
					else if(j + y[k] <= m) c[j + y[k]] ++;
				}
				c[i] += cnt;
			}
		}
		c[i] += c[i - 1];
		int ans = c[i];
		rep(j, 1, B) ans += s[j][i % j];
		cout << ans << '\n';
	}
	return 0;
}