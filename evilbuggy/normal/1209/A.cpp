#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int answer = 0;
	vector<int> used(n);
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++){
		if(used[i])continue;
		for(int j = i; j < n; j++){
			if(a[j]%a[i] == 0)used[j] = 1;
		}
		answer++;
	}
	cout << answer << '\n';

	return 0;
}