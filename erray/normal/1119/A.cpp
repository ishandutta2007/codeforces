#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	int ans = 0;
	for (int i = 0; i < n; ++i) if (v[i] != v[0]) ans = i;
	reverse(v.begin(), v.end());
	for (int i = 0; i < n; ++i) if (v[i] != v[0]) ans = max(i, ans);
	cout << ans << '\n';
}