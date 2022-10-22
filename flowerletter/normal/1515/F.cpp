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
const int maxn = 3e5;
int n, m, x, cnt, u, v, vis[maxn + 5], head[maxn+ 5];
ll sum, a[maxn + 5];
stack<int> s;
vector<int> t;
struct Edge {
	int to, next, id;
}e[maxn * 2 + 5];
void add(int u, int v, int w) {
	e[++cnt] = (Edge) {v, head[u], w}, head[u] = cnt; 
} 
void dfs(int u) {
	vis[u] = 1;
	trv(i, u, v) {
		if(vis[v]) continue;
		dfs(v);
		if(a[u] + a[v] >= x) a[u] += a[v] - x, t.push_back(e[i].id);
		else s.push(e[i].id);
		
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &x);
	rep(i, 1, n) scanf("%d", &a[i]), sum += a[i];
	if(sum < 1ll * x * (n - 1)) return puts("NO"), 0;
	rep(i, 1, m) scanf("%d%d", &u, &v), add(u, v, i), add(v, u, i);
	dfs(1);
	//rep(i, 1, n) if(!vis[i]) return puts("NO"), 0;
	puts("YES");
	for(auto x : t) printf("%d\n", x);
	while(!s.empty()) printf("%d\n", s.top()), s.pop();
	return 0;
}