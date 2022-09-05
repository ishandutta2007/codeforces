#include <bits/stdc++.h>

#include <vector>
#include <utility>

using std::vector, std::pair;

pair<vector<int>, vector<int>> sieve(int n) {
	vector<int> erat(n + 1);
	vector<int> primes;
	erat[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (erat[i] == 0) {
			erat[i] = i;
			primes.push_back(i);
		}
		for (int p : primes) {
			if (p > erat[i] || i * p > n) {
				break;
			}
			erat[i * p] = p;
		}
	}
	return {erat, primes};
}

vector<int> calc_phi(const vector<int>& erat) {
	const int n = erat.size();
	vector<int> phi(n);
	phi[1] = 1;
	for (int i = 2; i < n; ++i) {
		phi[i] = phi[i / erat[i]] * erat[i];
		if (erat[i] != erat[i / erat[i]]) {
			phi[i] -= phi[i / erat[i]];
		}
	}
	return phi;
}

vector<int> calc_mu(const vector<int>& erat) {
	const int n = erat.size();
	vector<int> mu(n);
	mu[1] = 1;
	for (int i = 2; i < n; ++i) {
		mu[i] = (erat[i] == erat[i / erat[i]]) ? 0 : -mu[i / erat[i]];
	}
	return mu;
}

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

constexpr int mod = 1'000'000'007;

void solve() {
	int n = nxt();
	auto erat = sieve(n).first;
	auto phi = calc_phi(erat);
	long long ans = 0;
	for (int d = 1; d < n; ++d) {
		for (int sab = d + d; sab < n; sab += d) {
			ans += lcm<long long>(n - sab, d) * phi[sab / d] % mod;
		}
	}
	cout << ans % mod << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	for (int i = 1; i <= t; ++i) {
		solve();
	}

	return 0;
}