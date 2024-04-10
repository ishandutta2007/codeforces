#include <bits/stdc++.h>
using namespace std;
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	for(cin >> T; T; T --) {
		int n, k;
		cin >> n >> k;
		vector<int> s(n);
		for(int i = n - k; i < n; i ++) cin >> s[i];
		int flag = 1;
		for(int i = n - k + 2; i < n; i ++) flag &= (s[i] - s[i - 1] >= s[i - 1] - s[i - 2]);
		if(k > 1) flag &= s[n - k] <= 1ll * (n - k + 1) * (s[n - k + 1] - s[n - k]);
		cout << (flag ? "YES\n" : "NO\n");
	} 
	return 0;
}