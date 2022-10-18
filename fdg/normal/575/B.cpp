#include <set>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <memory.h>
#include <queue> 
#include <cmath>

using namespace std;
#define pb push_back 
#define left hsfkasfhasfuckajsfkjsaf
#define right ajadslfkjasdklfj
#define distance fuck_this_shit
#define REP(i, n) for (int i = 0; i < n; ++i)
const int inf = 1000000000;
const int mod = 1000000007;
vector < pair < int, int > > g[200000];
int n, m, ans, k;
int timer;
int tin[200005];
int tout[200005];
int pw[2000005];
int c1[200005], c2[200005];
int pr[200005][20];
int E[200005];
int A[200005];
int B[200005];
int C[200005];
void dfs(int x, int p) {
	tin[x] = ++timer;
	pr[x][0] = p;
	for (int i = 1; i <= 17; ++i)
		pr[x][i] = pr[pr[x][i - 1]][i - 1];
	for (int i = 0; i < g[x].size(); ++i) {
		int to = g[x][i].first;
		if (to == p) continue;
		dfs(to, x);
	}
	tout[x] = ++timer;
}
bool isAnc(int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}
int lca(int a, int b){
	if (isAnc(a, b)) return a;
	if (isAnc(b, a)) return b;
	for (int i = 17; i >= 0; --i) {
		if (!isAnc(pr[a][i], b))
			a = pr[a][i];
	}
	return pr[a][0];
}
void run(int x, int p) {
	for (int i = 0; i < g[x].size(); ++i) {
		int to = g[x][i].first;
		if (to == p) continue;
		run(to, x);
		if (g[x][i].second == 1) {
			ans = (ans + (pw[c1[to]] - 1 + mod) % mod) % mod;
		} else if (g[x][i].second == 2){
			ans = (ans + (pw[c2[to]] - 1 + mod) % mod) % mod;
		}
		c1[x] += c1[to];
		c2[x] += c2[to];
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
		A[i]--; B[i]--;
		int v1 = 0, v2 = 0;
		if (C[i] == 1) {
			v1 = 1, v2 = 2;
		}
		g[A[i]].push_back(make_pair(B[i], v1));
		g[B[i]].push_back(make_pair(A[i], v2));
	}	
	dfs(0, 0);
	scanf("%d", &k);
	int last = 0;
	for (int i = 0; i < k; ++i) {
		int val;
		scanf("%d", &val);
		val--;
		c1[last]++; c2[val]++;
		int anc = lca(last, val);
		c1[anc]--;
		c2[anc]--;
		last = val;
	}
	pw[0] = 1;
	for (int i = 1; i <= 2000000; ++i) {
		pw[i] = pw[i - 1] * 2 % mod;
	}
	run(0, 0);
	cout << ans << endl;
	return 0;
}