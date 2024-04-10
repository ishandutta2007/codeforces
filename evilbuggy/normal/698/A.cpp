#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> dp(3, inf); dp[0] = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		vector<int> ndp(3, inf);
		if(x&1){
			ndp[1] = min(dp[0], dp[2]);
		}
		if(x&2){
			ndp[2] = min(dp[0], dp[1]);
		}
		ndp[0] = min({dp[0], dp[1], dp[2]}) + 1;
		dp = ndp;
	}
	cout << min({dp[0], dp[1], dp[2]}) << '\n';

	return 0;
}