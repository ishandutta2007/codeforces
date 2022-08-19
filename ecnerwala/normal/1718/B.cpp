#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	const int V = int(1e9);
	std::vector<int64_t> fib; fib.reserve(30);
	fib.push_back(1);
	fib.push_back(1);
	while (fib.back() <= V) {
		fib.push_back(fib.end()[-2] + fib.end()[-1]);
	}
	fib.push_back(fib.end()[-2] + fib.end()[-1]);
	fib.push_back(fib.end()[-2] + fib.end()[-1]);

	for (auto v : fib) { cerr << v << ' '; } cerr << '\n';

	int T; cin >> T;

	std::vector<int> cnts(fib.size());
	std::vector<int> bot_cnts(fib.size());
	while (T--) {
		int K; cin >> K;
		std::fill(cnts.begin(), cnts.end(), 0);
		std::fill(bot_cnts.begin(), bot_cnts.end(), 0);
		int64_t tot = 0;
		while (K--) {
			int64_t v; cin >> v;
			tot += v;
			for (int z = int(fib.size()) - 1; z >= 0; z--) {
				if (v >= fib[z]) {
					if (v == fib[z]) bot_cnts[z]++;
					v -= fib[z];
					cnts[z]++;
					z--;
				}
			}
			assert(v == 0);
		}
		auto it = std::lower_bound(fib.begin(), fib.end(), tot + 1);
		if (it == fib.end()) {
			cout << "NO" << '\n';
			continue;
		}
		int max_z = int(it - fib.begin()) - 2;
		bool good = true;
		for (int z = int(fib.size())-1; z >= 0; z--) {
			if (cnts[z] > (z <= max_z)) {
				if ((z & 1) && bot_cnts[z] > 0) {
					cnts[z]--;
					for (int i = z-1; i >= 0; i -= 2) cnts[i]++;
				}
			}
			if (cnts[z] != (z <= max_z)) {
				good = false;
				break;
			}
		}
		cout << (good ? "YES" : "NO") << '\n';
	}

	return 0;
}