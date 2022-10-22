#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <pii> from[200010];
long long dp1[200010], dp2[200010], dp3[200010], dp4[200010];
// 1: 1   2: 0   3: 01   4: 10
long long ans = 0;

void dfs(int x, int last){
	dp1[x] = dp2[x] = dp3[x] = dp4[x] = 0;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i].fi, id = from[x][i].se;
		if (v == last) continue;
		dfs(v, x);
		if (id == 0){
			dp2[x] += dp2[v] + 1;
			dp3[x] += dp3[v] + dp1[v];
		} else {
			dp1[x] += dp1[v] + 1;
			dp4[x] += dp4[v] + dp2[v];
		}
	}
	ans += 2 * dp1[x] + 2 * dp2[x] + dp3[x] + dp4[x];
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i].fi, id = from[x][i].se;
		if (v == last) continue;
		long long ndp1, ndp2, ndp3, ndp4;
		if (id == 0){
			ndp1 = ndp4 = 0;
			ndp2 = dp2[v] + 1;
			ndp3 = dp3[v] + dp1[v];
		} else {
			ndp2 = ndp3 = 0;
			ndp1 = dp1[v] + 1;
			ndp4 = dp4[v] + dp2[v];
		}
		ans += (dp1[x] - ndp1) * ndp1 + ndp4 * (dp1[x] - ndp1) + ndp2 * (dp1[x] - ndp1);
		ans += (dp2[x] - ndp2) * ndp2 + ndp2 * (dp3[x] - ndp3);
	}
}

int main(){
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++){
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		from[u].push_back(mp(v, c));
		from[v].push_back(mp(u, c));
	}
	dfs(1, 1);
	printf("%I64d\n", ans);
	return 0;
}