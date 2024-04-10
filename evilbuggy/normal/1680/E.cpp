#include <bits/stdc++.h>
using namespace std;

inline void trim(int &n, vector<string> &v){
	while(v[0].back() == '.' && v[1].back() == '.'){
		v[0].pop_back();
		v[1].pop_back();
		n--;
	}
	reverse(v[0].begin(), v[0].end());
	reverse(v[1].begin(), v[1].end());
	while(v[0].back() == '.' && v[1].back() == '.'){
		v[0].pop_back();
		v[1].pop_back();
		n--;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		vector<string> v(2);
		cin >> v[0] >> v[1];
		trim(n, v);
		vector<int> dp(2);
		if(v[0][0] == '*' && v[1][0] == '*'){
			dp[0] = dp[1] = 1;
		}else if(v[0][0] == '*'){
			dp[1] = 1;
		}else{
			dp[0] = 1;
		}
		for(int i = 1; i < n; i++){
			vector<int> ndp(2);
			if(v[0][i] == '*' && v[1][i] == '*'){
				ndp[0] = min(dp[0], dp[1]) + 2;
				ndp[1] = min(dp[0], dp[1]) + 2;
			}else if(v[0][i] == '*'){
				ndp[0] = min(dp[0] + 1, dp[1] + 2);
				ndp[1] = min(dp[0] + 2, dp[1] + 2);
			}else if(v[1][i] == '*'){
				ndp[0] = min(dp[0] + 2, dp[1] + 2);
				ndp[1] = min(dp[0] + 2, dp[1] + 1);
			}else{
				ndp[0] = min(dp[0] + 1, dp[1] + 2);
				ndp[1] = min(dp[0] + 2, dp[1] + 1);
			}
			dp = ndp;
		}
		cout << min(dp[0], dp[1]) << '\n';
	}

	return 0;
}