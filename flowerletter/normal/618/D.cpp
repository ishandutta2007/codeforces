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
const int maxn = 2e5;
int n, x, y, u, v;
int cnt, head[maxn + 5], ans;
struct Edge {int to, next;} e[maxn * 2 + 5];
inline void add(int u, int v) {
	e[++cnt] = (Edge) {v, head[u]}, head[u] = cnt;
}
bool dfs(int u, int par) {
	int cnt = 2;
	trv(i, u, v) if(v != par) {
		if(dfs(v, u)) cnt --;
	}
	ans += max(0, 1 - cnt);
	return cnt > 0;
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &n, &x, &y);
	rep(i, 2, n) scanf("%d%d", &u, &v), add(u, v), add(v, u); 
	if(x < y) printf("%lld\n", 1ll * (dfs(1, 1) + ans - 1) * (y - x) + 1ll * (n - 1) * x);
	else {
		rep(i, 1, n) {
			int deg = 0;
			trv(j, i, v) deg ++;
			if(deg == n - 1) return printf("%lld\n", 1ll * (n - 2) * y + x), 0;
		}
		printf("%lld\n", 1ll * (n - 1) * y);
	}
	return 0;
}