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

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}

const int maxn = 1e5;
const int B =  500;
const int inf = 1e9;

int n, x, u, mxdep, dep[maxn + 5], k[maxn + 5], col[maxn + 5];
bitset<maxn + 5> dp[B + 5];
int pre[B + 5][maxn + 5], cnt[maxn + 5];
vector<int> G[maxn + 5], p[maxn + 5], s;
vector<P> t;

void dfs(int u, int par) {
	p[dep[u] = dep[par] + 1].push_back(u);
	chkmx(mxdep, dep[u]); 
	for(auto v : G[u]) dfs(v, u);
}
int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &x);
	rep(i, 2, n) {
		scanf("%d", &u);
		G[u].push_back(i);
	}
	dfs(1, 1);
	rep(i, 1, mxdep) s.push_back(sz(p[i]));
	sort(all(s));
	rep(i, 0, sz(s) - 1) {
		if(i == 0 || s[i] != s[i - 1]) t.push_back({s[i], 1});
		else t.back().se++;
	}
	rep(i, 0, sz(t) - 1) {
		if(i) rep(j, 0, x) dp[i][j] = dp[i - 1][j];
		else dp[i][0] = 1;
		rep(j, 0, x) {
			if(dp[i][j]) k[j] = 0;
			else k[j] = j >= t[i].fi ? k[j - t[i].fi] + 1 : inf;
			if(k[j] <= t[i].se) dp[i][j] = 1, pre[i][j] = j - t[i].fi * k[j];
			else dp[i][j] = 0;
		}
	}
	if(dp[sz(t) - 1][x]) {
		int nw = x;
		per(i, sz(t) - 1, 0) {
			cnt[t[i].fi] = (nw - pre[i][nw]) / t[i].fi;
			nw = pre[i][nw];
		}
		rep(i, 1, mxdep) {
			if(cnt[sz(p[i])]) {
				cnt[sz(p[i])]--;
				for(auto u : p[i]) col[u] = 1;
			}
			else for(auto u : p[i]) col[u] = 2;
		}
		printf("%d\n", mxdep);
		rep(i, 1, n) assert(col[i]), putchar(col[i] == 1 ? 'a' : 'b');
	}
	else {
		int m = n, y = x;
		rep(i, 1, mxdep) {
			if(sz(p[i]) <= y) for(auto u : p[i]) col[u] = 1, y--, m--;
			else if(sz(p[i]) <= m - y) for(auto u : p[i]) col[u] = 2, m--;
			else {
				if(y < m - y) {
					for(auto u : p[i]) if(!G[u].empty()) col[u] = 2, m--;
					for(auto u : p[i]) if(G[u].empty()) col[u] = (m - y) ? (m--, 2) : (m--, y--, 1);
				}
				else {
					for(auto u : p[i]) if(!G[u].empty()) col[u] = 1, y--, m--;
					for(auto u : p[i]) if(G[u].empty()) col[u] = (y) ? (m--, y--, 1) : (m--, 2);
				}
			}
		}
		printf("%d\n", mxdep + 1);
		rep(i, 1, n) assert(col[i]), putchar(col[i] == 1 ? 'a' : 'b');
	}
	return 0;
}