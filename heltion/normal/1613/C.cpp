#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	for (cin >> t; t; t -= 1) {
		int n;
		LL h;
		cin >> n >> h;
		vector<LL> a(n);
		for (LL& ai : a) cin >> ai;
		cout << *ranges::partition_point(ranges::iota_view(1LL, h + 1), [&](LL k){
			LL sum = 0, R = 0;
			for (LL ai : a) {
				sum += ai + k - max(ai, R + 1);
				R = ai + k - 1;
			}
			return sum < h;
		}) << "\n";
	}
	return 0;
}