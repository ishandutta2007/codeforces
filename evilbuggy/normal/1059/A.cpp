#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, L, a;
	cin >> n >> L >> a;

	int ans = 0, prev = -1;
	for(int i = 0; i < n; i++){
		int t, l;
		cin >> t >> l;
		ans += (t - prev - 1)/a;
		prev = t + l - 1;
	}
	ans += (L - prev - 1)/a;
	cout << ans << '\n';

	return 0;
}