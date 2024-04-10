#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	const int inf = 1 << 25;
	vector<int> cost(8, inf);
	for(int i = 0; i < n; i++){
		int c;
		string s;
		cin >> c >> s;
		int mask = 0;
		for(auto ch : s){
			if(ch == 'A')mask |= 1;
			if(ch == 'B')mask |= 2;
			if(ch == 'C')mask |= 4;
		}
		cost[mask] = min(cost[mask], c);
	}
	for(int mask = 0; mask < 8; mask++){
		for(int mask1 = 0; mask1 < 8; mask1++){
			for(int mask2 = 0; mask2 < 8; mask2++){
				if((mask1 | mask2) == mask){
					cost[mask] = min(cost[mask], cost[mask1] + cost[mask2]);
				}
			}
		}
	}
	if(cost[7] == inf){
		cout << -1 << '\n';
	}else{
		cout << cost[7] << '\n';
	}

	return 0;
}