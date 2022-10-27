#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int mini = a[0];
	int ans = (int)1e9;
	for(int i = 2; i < n; i++){
		ans = min(ans, (mini + 1)/2 + (a[i] + 1)/2);
		mini = min(mini, a[i - 1]);
	}
	for(int i = 1; i < n; i++){
		int x = a[i - 1], y = a[i];
		ans = min(ans, max({(x + 1)/2, (y + 1)/2, (x + y + 2)/3}));
	}
	for(int i = 2; i < n; i++){
		int x = a[i - 2], y = a[i];
		ans = min(ans, 1 + x/2 + y/2);
	}
	cout << ans << '\n';

	return 0;
}