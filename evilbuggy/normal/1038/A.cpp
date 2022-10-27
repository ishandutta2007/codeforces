#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> f(k);
	for(int i = 0; i < n; i++){
		char ch; cin >> ch; f[ch - 'A']++;
	}
	int ans = n;
	for(int i = 0; i < k; i++){
		ans = min(ans, f[i]);
	}
	ans *= k;
	cout << ans << '\n';

	return 0;
}