#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<int> pfac(N+1);
	vector<int> primes; primes.reserve(N-1);
	vector<int> vals; vals.reserve(N-1);
	for (int i = 2; i <= N/2; i++) {
		if (!pfac[i]) {
			primes.push_back(i);
			pfac[i] = i;
		}
		for (int j = 0; j < int(primes.size()) && primes[j] <= min(pfac[i], N / i); j++) {
			pfac[i * primes[j]] = primes[j];
			vals.push_back(i);
		}
	}

	for (int z = N-1-int(vals.size()); z--; ) cout << "1" << ' ';
	for (auto v : vals) cout << v << ' ';
	cout << '\n';

	return 0;
}