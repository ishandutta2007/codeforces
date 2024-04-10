#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

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

auto erat = sieve(222222).first;

void solve() {
	int n = nxt(), q = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	vector<int> divs;
	for (int i = 1; i < n; ++i) {
		if (n % i == 0 && erat[n / i] == n / i) {
			divs.push_back(i);
		}
	}
	const int sz = divs.size();
	vector<vector<long long>> p(sz);
	for (int i = 0; i < sz; ++i) {
		int d = divs[i];
		p[i].resize(d);
		for (int j = 0; j < n; ++j) {
			p[i][j % d] += a[j];
		}
		for (auto& x : p[i]) {
			x *= d;
		}
	}
	multiset<long long> S;
	for (const auto& v : p) {
		for (auto x : v) {
			S.insert(x);
		}
	}

	cout << *S.rbegin() << "\n";
	while (q--) {
		int i = nxt() - 1;
		long long x = nxt() - a[i];
		a[i] += x;
		for (int j = 0; j < sz; ++j) {
			S.erase(S.find(p[j][i % divs[j]]));
			S.insert(p[j][i % divs[j]] += x * divs[j]);
		}
		cout << *S.rbegin() << "\n";
	}
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}