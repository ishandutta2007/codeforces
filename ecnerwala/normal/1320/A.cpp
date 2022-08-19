#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	map<int, long long> mp;
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int b; cin >> b;
		mp[b-i] += b;
	}
	long long ans = 0;
	for (auto it : mp) {
		ans = max(ans, it.second);
	}
	cout << ans << '\n';

	return 0;
}