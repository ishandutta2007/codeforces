#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<pair<int, int> > vec;
	for(int i = 0; i < n; i++){
		vec.emplace_back(a[i], i);
	}
	sort(vec.rbegin(), vec.rend());

	vector<int> use(n);
	long long total = 0;
	for(int i = 0; i < m*k; i++){
		use[vec[i].second] = 1;
		total += vec[i].first;
	}
	cout << total << '\n';
	for(int i = 0, cnt = 0; i < n; i++){
		cnt += use[i];
		if(cnt == m + 1){
			cout << i << " ";
			cnt = 1;
		}
	}
	cout << '\n';

	return 0;
}