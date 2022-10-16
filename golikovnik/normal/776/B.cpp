#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

bool is_prime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) return 0;
	} 
	return 1;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	if (n == 1) {
		cout << "1\n1\n";
		return 0;
	}	
	if (n == 2) {
		cout << "1\n1 1\n";
		return 0;
	}
	cout << "2\n";
	for (int i = 2; i <= n + 1; ++i) {
		if (i > 2) cout << " ";
		cout << is_prime(i) + 1;
	}
	cout << "\n";
	return 0;	
}