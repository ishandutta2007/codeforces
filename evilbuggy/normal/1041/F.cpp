#include <bits/stdc++.h>
using namespace std;

const int K = 32;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, y;
	cin >> n >> y;
	vector<long long> vec[K];
	for(int i = 0; i < n; i++){
		long long x; cin >> x;

		long long cur = 1;
		for(int j = 0; j < K; j++){
			vec[j].emplace_back(x & cur);
			cur = (cur << 1) | 1;
		}
	}
	cin >> m >> y;
	for(int i = 0; i < m; i++){
		long long x; cin >> x;

		long long cur = 1;
		for(int j = 0; j < K; j++){
			vec[j].emplace_back((x + (1LL << j)) & cur);
			cur = (cur << 1) | 1;
		}
	}
	int ans = 2;
	for(int j = 0; j < K; j++){
		sort(vec[j].begin(), vec[j].end());
		
		int cur = 1;
		for(int i = 1; i < (int)vec[j].size(); i++){
			if(vec[j][i] == vec[j][i - 1]){
				cur++;
			}else{
				cur = 1;
			}
			ans = max(ans, cur);
		}
	}
	cout << ans << '\n';

	return 0;
}