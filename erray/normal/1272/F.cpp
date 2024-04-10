#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	vector<vector<vector<int>>> val_dp(405, vector<vector<int>>(s.size() + 1, vector<int>(t.size() + 1, -1))), dir_dp = val_dp;
	function<int(int, int, int)> DP = [&](int val, int inds, int indt) {
		if(val == 404)return (int)1e7;
		if (inds == s.size() && indt == t.size()) return val_dp[val][inds][indt] = val;
		if (val_dp[val][inds][indt] != -1) return val_dp[val][inds][indt];
		int r1 = DP(val + 1, inds + (s[inds] == '('), indt + (t[indt] == '(')), r2 = 1e3;
		if (val) r2 = DP(val - 1, inds + (s[inds] == ')'), indt + (t[indt] == ')'));
		dir_dp[val][inds][indt] = r2 > r1;
		return val_dp[val][inds][indt] = min(r1, r2) + 1; 
	};
	DP(0, 0, 0);
	vector<int> cur(3);
	string ans;
	while (dir_dp[cur[0]][cur[1]][cur[2]] != -1) {
		bool b = dir_dp[cur[0]][cur[1]][cur[2]];
		char Add = (b ? '(' : ')');
		ans += Add;
		cur[1] += s[cur[1]] == Add; 
		cur[2] += t[cur[2]] == Add;
		cur[0] += (b ? 1 : -1);		
	}	
		cout << ans + string(val_dp[cur[0]][cur[1]][cur[2]], ')')<< '\n';
}