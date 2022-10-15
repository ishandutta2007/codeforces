#include<bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long n, h;
	cin >> n >> h;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int ans = 0;
	multiset<int, greater<int>> s;
	for (int i = 1; i <= n; ++i) {
		s.insert(a[i - 1]);
		long long h2 = h, b = 1;
		for (int el : s) {
			if (b) h2 -= el;
			b ^= 1;
		}
		if (h2 >= 0) ans = i;
	} 
	cout << ans << '\n';
}