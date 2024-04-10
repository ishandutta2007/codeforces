#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <pair <int, int>, int> piii;

int a[5010];
int dp[5010][5010];
vector <piii> v;
int n;

int dfs(int l, int r, int lid, int rid){
//	cout << "  dfs:" << l << " " << r << " " << lid << " " << rid << endl;
	if (l == 0 && r == n - 1) return 0;
	if (~dp[l][r]) return dp[l][r];
	if (lid == 0) return dp[l][r] = dfs(l, v[rid + 1].fi.se, lid, rid + 1) + 1;
	if (rid == v.size() - 1) return dp[l][r] = dfs(v[lid - 1].fi.fi, r, lid - 1, rid) + 1;
	if (v[lid - 1].se == v[rid + 1].se)
		return dp[l][r] = dfs(v[lid - 1].fi.fi, v[rid + 1].fi.se, lid - 1, rid + 1) + 1;
	return dp[l][r] = min(dfs(l, v[rid + 1].fi.se, lid, rid + 1), dfs(v[lid - 1].fi.fi, r, lid - 1, rid)) + 1;
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int last = 0;
	for (int i = 1; i < n; i++){
		if (a[i] != a[i - 1]) v.push_back(mp(mp(last, i - 1), a[i - 1])), last = i;
	}
	v.push_back(mp(mp(last, n - 1), a[n - 1]));
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < v.size(); i++){
		ans = min(ans, dfs(v[i].fi.fi, v[i].fi.se, i, i));
	}
	printf("%d\n", ans);
	return 0;
}