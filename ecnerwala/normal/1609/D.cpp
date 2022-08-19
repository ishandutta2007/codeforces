#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, D; cin >> N >> D;

	std::map<int, int> big;
	std::map<int, int> small;

	for (int z = 0; z < N; z++) small[1]++;
	big[1]++;
	int sum = 1;

	std::vector<int> par(N, -1);
	auto get_par = [&](int a) -> int {
		while (par[a] >= 0) {
			if (par[par[a]] >= 0) par[a] = par[par[a]];
			a = par[a];
		}
		return a;
	};
	auto merge = [&](int a, int b) -> bool {
		a = get_par(a);
		b = get_par(b);
		if (a == b) {
			// move one from small to big
			if (!small.empty()) {
				auto it = small.end();
				--it;
				sum += it->first;
				big[it->first]++;
				it->second--;
				if (!it->second) {
					small.erase(it);
				}
			}
			return false;
		}
		if (par[a] > par[b]) std::swap(a, b);
		int big_sz = 0;
		auto erase = [&](int sz) -> void {
			{
				auto it = small.find(sz);
				if (it != small.end()) {
					it->second--;
					if (!it->second) small.erase(it);
					return;
				}
			}

			{
				auto it = big.find(sz);
				assert(it != big.end());
				big_sz--;
				sum -= it->first;
				it->second--;
				if (!it->second) big.erase(it);
			}
		};
		erase(-par[a]);
		erase(-par[b]);
		par[a] += par[b];
		par[b] = a;
		{
			big_sz++;
			sum += -par[a];
			big[-par[a]]++;
		}
		while (big_sz < 0) {
			// bump small to big
			if (!small.empty()) {
				auto it = small.end();
				--it;
				sum += it->first;
				big[it->first]++;
				it->second--;
				if (!it->second) {
					small.erase(it);
				}
			}
			big_sz++;
		}
		while (big_sz > 0) {
			big_sz--;
			auto it = big.begin();
			assert(it != big.end());
			sum -= it->first;
			it->second--;
			small[it->first]++;
			if (!it->second) big.erase(it);
		}
		return true;
	};

	for (int i = 0; i < D; i++) {
		int u, v; cin >> u >> v; u--, v--;
		merge(u, v);
		cout << sum-1 << '\n';
	}

	return 0;
}