#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	reverse(a.begin(), a.end());
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += max(0, a[i]);
		if (i != n - 1) {
			a[i + 1] = min(a[i + 1], a[i] - 1);
		}
	}
	cout << ans;
}