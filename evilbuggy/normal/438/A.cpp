#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		int u; cin >> u;
		int v; cin >> v;
		ans += min(a[u - 1], a[v - 1]);
	}
	cout << ans << '\n';

	return 0;
}