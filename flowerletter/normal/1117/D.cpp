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
inline ll read() {
	ll x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 100;
const int mod = 1e9 + 7;
ll n, m;
inline int add(int a, int b) {return (a += b) >= mod ? a - mod : a;}
inline int mul(int a, int b) {return 1ll * a * b % mod;}
struct Matrix {
	int a[maxn + 5][maxn + 5];
	Matrix () {memset(a, 0, sizeof a);}
	int* operator [] (int x) {return a[x];}
	friend Matrix operator * (Matrix x, Matrix y) {
		Matrix ans;
		rep(i, 0, m - 1) rep(j, 0, m - 1) rep(k, 0, m - 1) ans[i][j] = add(ans[i][j], mul(x[i][k], y[k][j]));
		return ans;
	}
}base, ans;
inline Matrix fpw(Matrix a, ll b) {
	for(; b; b >>= 1, a = a * a) if(b & 1) ans = ans * a;
	return ans;
}
int main() {
//	freopen("in.txt", "r", stdin);
	n = read(), m = read();
	rep(i, 1, m - 1) base[i - 1][i] = 1;
	base[m - 1][0] = 1, base[0][0] = 1;
	ans[0][0] = 1;
	cout << fpw(base, n)[0][0] << '\n';
	return 0;
}