#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
vector<pi> cur[maxn]; // 
int dp[maxn];
void ins(int id, int num, int cc) {
	for (int j = 0; j < cur[id].size(); j++)
		if (cur[id][j].fi == num) {
			cur[id][j].se += cc;
			return ;
		}
	if (cur[id].size() <= 2) 
		cur[id].pb(mp(num, cc));
} 
int cal(int id) {
	if (cur[id].size() == 0) return 0;
	int cnt = 0, us = 0;
	for (auto v : cur[id]) {
		if (v.se == 0) continue;
		cnt++;
		us = v.fi;
		if (cnt >= 2) return maxn; 
	}
	return us;
}
vi eg[maxn];
void dfs1(int a, int fa) {
	for (auto v : eg[a]) {
		if (v == fa) continue;
		dfs1(v, a);
		int cu = cal(v);
		ins(a, cu + 1, 1);
	}
}
void dfs2(int a, int fa) {
	if (fa) {
		int cu = cal(a) + 1;
		ins(fa, cu, -1);
		ins(a, cal(fa) + 1, 1);
		ins(fa, cu, 1);
	}
	for (auto v : eg[a]) {
		if (v == fa) continue;
		dfs2(v, a);
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u].pb(v), eg[v].pb(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	int ca = maxn;
	for (int i = 1; i <= n; i++) {
		if (cur[i].size() > 2) continue;
		int cu = 0;
		for (auto v : cur[i])
			cu += v.fi;
		if (cu > n - 1) continue;
		while (cu % 2 == 0) cu /= 2;
		ca = min(ca, cu);
	}
	if (ca > n - 1) cout << -1 << endl;
	else cout << ca << endl;
	return 0;
}
/*
CHHOCH
*/