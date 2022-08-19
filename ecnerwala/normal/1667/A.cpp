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

	int N; cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int64_t ans = 1e18;
	for (int i = 0; i < N; i++) {
		int64_t cnd = 0;
		{
			int64_t cur = 0;
			for (int j = i+1; j < N; j++) {
				cnd += cur / A[j] + 1;
				cur = (cur / A[j] + 1) * A[j];
			}
		}
		{
			int64_t cur = 0;
			for (int j = i-1; j >= 0; j--) {
				cnd += cur / A[j] + 1;
				cur = (cur / A[j] + 1) * A[j];
			}
		}
		ans = std::min(ans, cnd);
	}
	cout << ans << '\n';

	return 0;
}