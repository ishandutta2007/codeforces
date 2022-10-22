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
const int maxn = 1e6;
int n, u, v, opt[maxn + 5], val[maxn + 5], son[maxn + 5][2], tag[maxn + 5];
char s[5];
vector<P> ans;
void dfs(int u) {
	if(!u) return ;
	dfs(son[u][0]), dfs(son[u][1]);
	if(opt[u] == 1) {
		val[u] = val[son[u][0]] & val[son[u][1]];
		if(!val[son[u][0]]) tag[son[u][1]] = 1;
		if(!val[son[u][1]]) tag[son[u][0]] = 1; 
	}
	if(opt[u] == 2) {
		val[u] = val[son[u][0]] | val[son[u][1]];
		if(val[son[u][0]]) tag[son[u][1]] = 1;
		if(val[son[u][1]]) tag[son[u][0]] = 1;
	}
	if(opt[u] == 3) val[u] = val[son[u][0]] ^ val[son[u][1]];
	if(opt[u] == 4) val[u] = !val[son[u][0]];
}
void pushall(int u) {
	if(!u) return ;
	if(!opt[u]) ans.push_back({u, 1 - tag[u] ^ val[1]});
	if(tag[u]) tag[son[u][0]] = tag[son[u][1]] = 1;
	pushall(son[u][0]), pushall(son[u][1]);
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%s", s + 1);
		if(s[1] == 'I') scanf("%d", &val[i]);
		else if(s[1] == 'A') opt[i] = 1, scanf("%d%d", &son[i][0], &son[i][1]); 
		else if(s[1] == 'O') opt[i] = 2, scanf("%d%d", &son[i][0], &son[i][1]);
		else if(s[1] == 'X') opt[i] = 3, scanf("%d%d", &son[i][0], &son[i][1]);
		else if(s[1] == 'N') opt[i] = 4, scanf("%d", &son[i][0]);
	}
	dfs(1), pushall(1), sort(all(ans));
	for(auto x : ans) putchar(x.se + '0');
	return 0;
}