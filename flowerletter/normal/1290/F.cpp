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
const int maxn = 5;
const int lg = 30;
const int maxk = 20;
const int mod = 998244353;
int n, m, x[maxn + 5], y[maxn + 5];
int f[lg + 1][maxk + 5][maxk + 5][maxk + 5][maxk + 5][2][2], vis[lg + 1][maxk + 5][maxk + 5][maxk + 5][maxk + 5][2][2];
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int sub(int a, int b) {return (a -= b) < 0 ? a + mod : a;}
int dp(int len, int a, int b, int c, int d, int isx, int isy) {
	if(len == lg + 1) return !a && !b && !c && !d && isx && isy;
	if(vis[len][a][b][c][d][isx][isy]) return f[len][a][b][c][d][isx][isy];
	vis[len][a][b][c][d][isx][isy] = 1;
	int &res = f[len][a][b][c][d][isx][isy]; 
	rep(s, 0, (1 << n) - 1) {
		int da = a, db = b, dc = c, dd = d; 
		rep(i, 1, n) if(s >> i - 1 & 1){
			if(x[i] > 0) da += x[i];
			else db += -x[i];
			if(y[i] > 0) dc += y[i];
			else dd += -y[i];
		}
		if((da & 1) != (db & 1) || (dc & 1) != (dd & 1)) continue;
		int disx = (da & 1) == (m >> len & 1) ? isx : (da & 1) < (m >> len & 1), 
			disy = (dc & 1) == (m >> len & 1) ? isy : (dc & 1) < (m >> len & 1);
		res = add(res, dp(len + 1, da >> 1, db >> 1, dc >> 1, dd >> 1, disx, disy));
	}
	return res;
}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), m = read();
	rep(i, 1, n) x[i] = read(), y[i] = read();
	cout << sub(dp(0, 0, 0, 0, 0, 1, 1), 1) << '\n';
	return 0;
}