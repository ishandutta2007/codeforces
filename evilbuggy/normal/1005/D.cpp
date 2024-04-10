#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	vector<int> dp({0, -(int)1e6, -(int)1e6});
	for(auto ch : s){
		int dig = ch - '0';
		vector<int> ndp({-(int)1e6, -(int)1e6, -(int)1e6});
		for(int p = 0; p < 3; p++){
			int np = (p + dig)%3;
			if(np == 0){
				ndp[np] = max(ndp[np], dp[p] + 1);
			}else{
				ndp[np] = max(ndp[np], dp[p]);
			}
			if(dig%3 == 0){
				ndp[dig%3] = max(ndp[dig%3], dp[p] + 1);
			}else{
				ndp[dig%3] = max(ndp[dig%3], dp[p]);
			}
		}
		dp = ndp;
	}
	cout << *max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}