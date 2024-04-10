#include <bits/stdc++.h>
using namespace std;
int main() {
	// two magical lines to speed up IO
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		// 1 + 3 + 5 + 7 + 9 + ...
		int first = 1;
		int last = 2 * k - 1;
		long long sum = (long long) k * (first + last) / 2;
		if(n >= sum && n % 2 == sum % 2) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}