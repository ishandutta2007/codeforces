#include <bits/extc++.h>

static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();

struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

std::mt19937 mt(FIXED_RANDOM);

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	// we can binary search on answer; to do a single round of binary search, we use PIE to check for each value
	int N, M; cin >> N >> M;
	std::vector<std::pair<int64_t, std::array<int, 32>>> A(N);
	hash_map<int, std::mt19937::result_type> val_map;
	int num_sets = 0;
	hash_map<std::mt19937::result_type, int> set_map;
	for (auto& a : A) {
		std::array<std::mt19937::result_type, 32> sets;
		sets[0] = 0;
		for (int j = 0; j < M; j++) {
			int v; cin >> v;
			if (val_map.find(v) == val_map.end()) {
				val_map[v] = mt();
			}
			std::mt19937::result_type r = val_map[v];
			for (int i = 0; i < (1<<j); i++) {
				sets[i + (1<<j)] = sets[i] ^ r;
			}
		}
		for (int i = 0; i < (1<<M); i++) {
			if (set_map.find(sets[i]) == set_map.end()) {
				set_map.insert({sets[i], num_sets++});
			}
			a.second[i] = set_map[sets[i]];
		}
		cin >> a.first;
	}
	std::sort(A.begin(), A.end(), [&](const auto& a, const auto& b) { return a.first < b.first; });

	auto can_below = [&](int64_t max_sum) -> bool {
		std::vector<int> cnt(num_sets);
		for (int i = N-1, j = 0; i >= 0; i--) {
			for (; j < N && A[j].first + A[i].first <= max_sum; j++) {
				for (int z = 0; z < (1<<M); z++) {
					cnt[A[j].second[z]]++;
				}
			}
			int val = 0;
			for (int z = 0; z < (1 << M); z++) {
				val += cnt[A[i].second[z]] * ((__builtin_popcount(z) & 1) ? -1 : 1);
			}
			assert(val >= 0);
			if (val > 0) {
				return true;
			}
		}
		return false;
	};
	int64_t mi = 0, ma = 2 * A.back().first + 1;
	while (ma - mi > 1) {
		int64_t md = mi + (ma - mi) / 2;
		if (can_below(md)) {
			ma = md;
		} else {
			mi = md;
		}
	}
	if (ma > 2 * A.back().first) {
		cout << -1 << '\n';
	} else {
		cout << ma << '\n';
	}

	return 0;
}