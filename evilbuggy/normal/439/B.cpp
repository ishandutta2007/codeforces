#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int x; cin >> x;
	vector<int> c(n);
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	long long ans = 0;
	sort(c.begin(), c.end());
	for(int i = 0; i < n; i++){
		ans += 1LL*max(1, x - i)*c[i];
	}
	cout << ans << '\n';

	return 0;
}