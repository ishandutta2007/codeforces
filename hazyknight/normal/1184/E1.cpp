#include <bits/stdc++.h>
#define il inline
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define mid ((l+r)>>1)
#define MAXN 1000005
#define MAXM
#define mod
#define inf (1<<30)
#define eps (1e-6)
#define alpha 0.75
#define rep(i, x, y) for(register int i = x; i <= y; ++i)
#define repd(i, x, y) for(register int i = x; i >= y; --i)
#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef pair <ll, ll> pll;
template <typename T> il bool chkmin(T &x, T y) {return x > y ? x = y, 1 : 0;}
template <typename T> il bool chkmax(T &x, T y) {return x < y ? x = y, 1 : 0;}
template <typename T> il void read(T &x) {
	char ch = getchar(); int f = 1; x = 0;
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = x*10+ch-'0', ch = getchar();
	x *= f;
}
template <typename T, typename... Args> il void read(T &x, Args &...args) {
	read(x), read(args...);
}
int n, m, fa[MAXN];
struct node {
	int u, v, w;
} E[MAXN];
int get(int u) {
	return u == fa[u] ? u : fa[u] = get(fa[u]);
}
int main() {
	int u, v, w;
	read(n, m);
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m) read(u, v, w), E[i] = node {u, v, w};
	sort(E+2, E+m+1, [&](const node &x, const node &y) {
		return x.w < y.w;
	});
	int uu = E[1].u, vv = E[1].v;
	rep(i, 2, m) {
		u = E[i].u, v = E[i].v, w = E[i].w;
		u = get(u), v = get(v);
		if((u == uu && v == vv) || (u == vv && v == uu)) return 0 * printf("%d\n", w);
		else if(u == uu || u == vv) fa[v] = u;
		else fa[u] = v;
	}
	puts("1000000000");
	return 0;
}