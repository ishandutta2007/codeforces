#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int> > vec;
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < 4; j++){
			int x;
			cin >> x;
			sum += x;
		}
		vec.emplace_back(sum, i);
	}
	sort(vec.begin(), vec.end(), [&](pair<int, int> x, pair<int, int> y){
		if(x.first != y.first)return x.first > y.first;
		return x.second < y.second;
	});
	for(int i = 0; i < n; i++){
		if(vec[i].second == 0){
			cout << i + 1 << '\n';
			exit(0);
		}
	}
	assert(false);

	return 0;
}