#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	set<long long> good;
	vector<int> is_prime(1e6 + 20);
	fill(is_prime.begin(), is_prime.end(), 1);
	for (int i = 2; i < 1e6; ++i) {
		if (!is_prime[i]) continue;
		for (int j = i + i; j <= 1e6; j += i) is_prime[j] = 0;
		good.insert(1LL * i * i);
	}
	while (n--) {
		long long k;
		cin >> k;
		cout << (good.count(k) ? "YES" : "NO") << "\n";
	}
	return 0;
}