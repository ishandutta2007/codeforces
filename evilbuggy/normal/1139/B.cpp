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
	reverse(a.begin(), a.end());
	long long answer = a[0];
	for(int i = 1; i < n; i++){
		a[i] = max(0, min(a[i], a[i - 1] - 1));
		answer += a[i];		
	}
	cout << answer << '\n';

	return 0;
}