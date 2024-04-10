#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int sum = n + m;
	int i = 0;
	int ans = 1;
	for (int i = 0; i < n + m; i++) {
		ans = (ans * 2) % 998244353;
	}
	cout << ans;
	return 0;
}