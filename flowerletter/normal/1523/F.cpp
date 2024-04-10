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
const int maxn = 14;
const int maxm = 100;
const int maxs = 1 << 14;
const int inf = 2e9;
int n, m, all, xa[maxn + 5], ya[maxn + 5], xb[maxm +5], yb[maxm + 5], t[maxm + 5];
int _xb[maxm +5], _yb[maxm + 5], _t[maxm + 5], id[maxm + 5];
int f[maxs + 5][maxm + 5], g[maxs + 5][maxm + 5], d1[maxs + 5][maxn + 5], d2[maxs + 5][maxm + 5];
inline int dis(int x1, int y1, int x2, int y2) {return abs(x1 - x2) + abs(y1 - y2);}
inline int lg(int x) {return log2(x) + 1;}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m), all = 1 << n;
	rep(i, 1, n) scanf("%d%d", &xa[i], &ya[i]);
	rep(i, 1, m) scanf("%d%d%d", &_xb[i], &_yb[i], &_t[i]), id[i] = i;
	sort(id + 1, id + m + 1, [&] (int x, int y) {return _t[x] < _t[y];});
	rep(i, 1, m) xb[i] = _xb[id[i]], yb[i] = _yb[id[i]], t[i] = _t[id[i]];
	rep(i, 1, n) d1[0][i] = inf; rep(i, 1, m) d2[0][i] = inf; 
	rep(s, 1, all - 1) rep(i, 1, n) d1[s][i] = min(d1[s ^ lb(s)][i], dis(xa[lg(lb(s))], ya[lg(lb(s))], xa[i], ya[i])); 
	rep(s, 1, all - 1) rep(i, 1, m) d2[s][i] = min(d2[s ^ lb(s)][i], dis(xa[lg(lb(s))], ya[lg(lb(s))], xb[i], yb[i]));
	rep(s, 0, all - 1) rep(i, 0, m) f[s][i] = inf, g[s][i] = -inf;
	rep(i, 1, m) g[0][i] = 1;
	rep(i, 1, n) f[1 << i - 1][0] = 0;
	rep(s, 0, all - 1) rep(i, 0, m) {
		if(f[s][i] != inf) {
			//cout << "f:" << s << ' ' << i << ' ' << f[s][i] << endl;
			rep(j, 1, n) if(!(s & (1 << j - 1))) chkmn(f[(1 << j - 1) | s][i], f[s][i] + d1[s][j]);
			rep(j, 1, m) if(f[s][i] + d2[s][j] <= t[j]) chkmx(g[s][j], i + 1);
		}
		if(g[s][i] != -inf) {
			//cout << "g:" << s << ' ' << i << ' ' << g[s][i] << endl;
			rep(j, 1, n) if(!(s & (1 << j - 1))) 
				chkmn(f[(1 << j - 1) | s][g[s][i]], t[i] + min(dis(xb[i], yb[i], xa[j], ya[j]), d1[s][j]));
			rep(j, 1, m) if(j != i && t[i] + min(dis(xb[i], yb[i], xb[j], yb[j]), d2[s][j]) <= t[j]) 
				chkmx(g[s][j], g[s][i] + 1);
		}
	}
	int ans = 0;
	rep(s, 0, all - 1) rep(i, 1, m) chkmx(ans, g[s][i]);
	printf("%d\n", ans);
	return 0;
}