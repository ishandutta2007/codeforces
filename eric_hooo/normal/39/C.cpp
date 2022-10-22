#include <bits/stdc++.h>
using namespace std;

vector <int> ids;
vector <int> all[4010];
int dp[4010][4010];
int ll[4010], rr[4010];
int mid[4010][4010];
int num[4010][4010];

int dfs(int l, int r){
	if (l > r) return 0;
	if (~dp[l][r]) return dp[l][r];
	int &res = dp[l][r] = dfs(l + 1, r);
	mid[l][r] = -1;
	for (int i = 0; i < all[l].size(); i++){
		int k = all[l][i];
		if (k >= r) continue;
		int val = dfs(l, k) + dfs(k, r);
		if (val > res) mid[l][r] = k, res = val;
	}
	if (num[l][r]) res++;
	return res;
}

void get_ans(int l, int r){
	if (l > r) return ;
	if (num[l][r]) printf("%d ", num[l][r]);
	if (mid[l][r] == -1) get_ans(l + 1, r);
	else {
		int k = mid[l][r];
		get_ans(l, k), get_ans(k, r);
	}
}

int main(){
	memset(dp, -1, sizeof(dp));
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int c, r; scanf("%d%d", &c, &r);
		ll[i] = c - r, rr[i] = c + r;
		ids.push_back(c - r), ids.push_back(c + r);
	}
	sort(ids.begin(), ids.end());
	ids.resize(unique(ids.begin(), ids.end()) - ids.begin());
	for (int i = 0; i < n; i++){
		int l = lower_bound(ids.begin(), ids.end(), ll[i]) - ids.begin();
		int r = lower_bound(ids.begin(), ids.end(), rr[i]) - ids.begin();
		all[l].push_back(r);
		num[l][r] = i + 1;
	}
	printf("%d\n", dfs(0, ids.size() - 1));
	get_ans(0, ids.size() - 1);
	printf("\n");
	return 0;
}