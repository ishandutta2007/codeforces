#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, cost[3];
	cin >> n >> cost[0] >> cost[1];
	
	vector<int> suit(n);
	for(int i = 0; i < n; i++){
		cin >> suit[i];
	}
	int ans = 0;
	for(int i = 0; i + i + 1 < n; i++){
		int j = n - 1 - i;
		if(suit[i] == 2 && suit[j] == 2){
			ans += 2*min(cost[0], cost[1]);
		}else if(suit[i] == 2){
			ans += cost[suit[j]];
		}else if(suit[j] == 2){
			ans += cost[suit[i]];
		}else if(suit[i] != suit[j]){
			cout << -1 << '\n';
			exit(0);
		}
	}
	if(n&1){
		if(suit[n >> 1] == 2){
			ans += min(cost[0], cost[1]);
		}
	}
	cout << ans << '\n';

	return 0;
}