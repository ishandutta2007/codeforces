#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, f;
	cin >> n >> f;
	long long answer = 0;
	vector<int> increment;
	for(int i = 0; i < n; i++){
		int k, l;
		cin >> k >> l;
		answer += min(k, l);
		increment.emplace_back(min(k + k, l) - min(k, l));
	}
	sort(increment.rbegin(), increment.rend());
	for(int i = 0; i < f; i++){
		answer += increment[i];
	}
	cout << answer << '\n';

	return 0;
}