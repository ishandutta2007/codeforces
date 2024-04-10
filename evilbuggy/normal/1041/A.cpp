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
	int ans = 1 - n;
	ans += *max_element(a.begin(), a.end());
	ans -= *min_element(a.begin(), a.end());
	cout << ans << '\n';

	return 0;
}