#include <bits/extc++.h>

struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	bool has_root = false;
	hash_map<int, vector<pair<int, int>>> mp;

	auto get_jmp = [&](array<int, 2> p) -> pair<bool, array<int, 2>> {
		assert(!(p[0] & p[1]));
		if (p[0] == 0 && p[1] == 0) {
			return {false, {-1,0}};
		}
		if (!((p[0]-1) & p[1])) {
			// decrease 0
			return {false, {p[0] & ~(p[1]-1), p[1]}};
		} else {
			return {true, {p[0], p[1] & ~(p[0]-1)}};
		}
	};
	auto dep = [&](array<int, 2> p) { return p[0] + p[1]; };

	int M; cin >> M;
	while (M--) {
		array<int, 2> v1, v2; cin >> v1[0] >> v1[1] >> v2[0] >> v2[1];
		while (true) {
			if (dep(v1) == 0 && dep(v2) == 0) {
				has_root = true;
				break;
			}

			auto [d1, n1] = get_jmp(v1);
			auto [d2, n2] = get_jmp(v2);
			assert(n1[!d1] == v1[!d1]);
			assert(n2[!d2] == v2[!d2]);

			if (d1 == d2 && n1 == n2) {
				// get the deeper of the two
				int x1 = dep(v1), x2 = dep(v2);
				if (x1 > x2) swap(x1, x2);
				assert(x1 <= x2);
				mp[n1[!d1] * 2 + d1].push_back({x1-1, x2});
				break;
			}

			if (dep(n1) > dep(n2)) { swap(n1, n2), swap(d1, d2), swap(v1, v2); }
			assert(dep(n1) <= dep(n2));

			mp[n2[!d2] * 2 + d2].push_back({dep(n2), dep(v2)});
			v2 = n2;
		}
	}

	hash_map<int, bool> tot_flip;

	if (has_root) tot_flip[0] ^= 1;
	for (auto& [_, vec] : mp) {
		sort(vec.begin(), vec.end());
		int cur_hi = -1;
		for (auto it : vec) {
			if (it.first > cur_hi) {
				if (cur_hi >= 0) tot_flip[cur_hi] ^= 1;
				tot_flip[it.first] ^= 1;
			}
			cur_hi = max(cur_hi, it.second);
		}
		if (cur_hi >= 0) {
			tot_flip[cur_hi] ^= 1;
		}
	}

	int ans = 0;
	for (auto it : tot_flip) {
		if (it.second) {
			ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}