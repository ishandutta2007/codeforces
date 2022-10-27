#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int> > cost(m);
	for(int i = 0; i < n; i++){
		int p, c;
		cin >> p >> c;
		cost[p - 1].emplace_back(c);
	}
	for(int i = 0; i < m; i++){
		sort(cost[i].begin(), cost[i].end());
	}
	long long ans = LLONG_MAX;
	for(int i = 0; i < n; i++){
		int cnt = 0;
		long long sum = 0;
		vector<int> excess;
		for(int j = 1; j < m; j++){
			int s = (int)cost[j].size();
			for(int k = 0; k < s; k++){
				if(k < s - i){
					sum += cost[j][k]; cnt++;
				}else{
					excess.emplace_back(cost[j][k]);
				}
			}
		}
		sort(excess.rbegin(), excess.rend());
		cnt += (int)cost[0].size();
		while(cnt <= i){
			sum += excess.back(); excess.pop_back(); cnt++;
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';

	return 0;
}