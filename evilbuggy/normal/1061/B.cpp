#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ind = 0;
	long long ans = 0;
	sort(a.begin(), a.end());
	for(int i = 0; i + 1 < n; i++){
		ans += a[i] - 1;
		if(ind + 1 <= a[i])ind++;
	}
	ans += min(a[n - 1] - 1, ind);
	cout << ans << '\n';

	return 0;
}