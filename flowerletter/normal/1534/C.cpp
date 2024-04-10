/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 4e5;
const int mod = 1e9 + 7;
int T, n, ans, a[maxn + 5], b[maxn + 5], fpw[maxn + 5];
int fa[maxn + 5];
void clear() {rep(i, 1, n) fa[i] = i;}
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx == fy) return ;
	fa[fx] = fy;
}
int main() {
//	freopen("in.txt", "r", stdin);
	fpw[0] = 1;
	rep(i, 1, maxn) fpw[i] = fpw[i - 1] * 2 % mod;
	for(scanf("%d", &T); T; T--) {
		scanf("%d", &n), clear(), ans = 0;
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) scanf("%d", &b[i]);
		rep(i, 1, n) merge(a[i], b[i]);
		rep(i, 1, n) ans += find(i) == i;
		printf("%d\n", fpw[ans]);
	}
	return 0;
}