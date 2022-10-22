/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;
 
template <typename T> bool chkmax(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmin(T &x, T y){return x > y ? x = y, true : false;}
 
const int maxn = 1e5;
 
int n, u, v, w, cnt, rt, tot, mn;
struct Edge {
	int to, next, w;
}e[maxn * 2 + 5];
int dep[maxn + 5], fa[maxn + 5], vis[maxn + 5], head[maxn + 5];
int mx[maxn + 5], col[maxn + 5], size[maxn + 5];
priority_queue<int, vector<int>, greater<int>> Q[maxn + 5];
set<P> all, S;
ll ans;
void add(int u, int v, int w) {
	e[++cnt] = (Edge) {v, head[u], w}, head[u] = cnt;
	e[++cnt] = (Edge) {u, head[v], w}, head[v] = cnt;
}
void findrt(int u, int par) {
	size[u] = 1;
	trv(i, u) {
		int v = e[i].to;
		if(v == par) continue;
		findrt(v, u);
		chkmax(mx[u], size[v]);
		size[u] += size[v];
		ans += 1ll * min(size[v], n - size[v]) * e[i].w;
	}
	chkmax(mx[u], n - size[u]);
	if(chkmin(mn, mx[u])) mn = mx[u], rt = u;
}
int dfs(int u, int par, int k) {
	Q[col[u] = k].push(u);int size = 1;
	trv(i, u) {
		int v = e[i].to;
		if(v == par) continue;
		dep[v] = dep[fa[v] = u] + e[i].w;
		size += dfs(v, u, k);
	}
	return size;
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	rep(i, 2, n) scanf("%d%d%d", &u, &v, &w), add(u, v, w);
	mn = 1e9, findrt(1, 1), printf("%lld\n", ans * 2);
	all.insert({rt, 0}), Q[0].push(rt), S.insert({size[0] = 2, 0});
	trv(i, rt) {
		int v = e[i].to; tot++;
		S.insert({size[tot] = dfs(v, rt, tot) * 2, tot});
		all.insert({Q[tot].top(), tot});
	}
	rep(i, 1, n) {
		int up = n - i;P mx = *S.rbegin(), mx1 = *all.begin();
		if(mx.fi > up && col[i] != mx.se && Q[mx.se].top() != rt) {
			int ans = Q[mx.se].top();
			S.erase({size[mx.se], mx.se}); 
			S.insert({--size[mx.se], mx.se});
			printf("%d ", ans);
			Q[mx.se].pop();
			all.erase({ans, mx.se});
			if(!Q[mx.se].empty()) all.insert({Q[mx.se].top(), mx.se});
		}
		else if(mx1.se == col[i] && i != rt){
			all.erase(mx1);
			P mx2 = *all.begin();
			S.erase({size[mx2.se], mx2.se});
			S.insert({--size[mx2.se], mx2.se});
			printf("%d ", mx2.fi);
			Q[mx2.se].pop();
			all.erase(mx2);
			if(!Q[mx2.se].empty()) all.insert({Q[mx2.se].top(), mx2.se});
			all.insert(mx1);
		}
		else {
			printf("%d ", mx1.fi);
			S.erase({size[mx1.se], mx1.se}); 
			S.insert({--size[mx1.se], mx1.se});
			Q[mx1.se].pop();
			all.erase(mx1);
			if(!Q[mx1.se].empty()) all.insert({Q[mx1.se].top(), mx1.se});
		}
		S.erase({size[col[i]], col[i]});
		S.insert({--size[col[i]], col[i]});
	}
	return 0;
}