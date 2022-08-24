#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	long long ans = 0;
	for (int b = 1; b <= 1e8; b *= 2) {
		vector<int> nums[2];
		for (int x : a) {
			nums[!!(x & b)].push_back(x & (b - 1));
		}
		for (int i = 0; i < 2; ++i) {
			sort(all(nums[i]));
		}

		long long cnt = 0;
		for (int i = 0, j = (int)nums[1].size() - 1; i < (int)nums[0].size(); ++i) {
			while (j >= 0 && nums[0][i] + nums[1][j] >= b) {
				--j;
			}
			cnt += j + 1;
		}

		for (int c : {0, 1}) {
			const auto& vec = nums[c];
			for (int i = 0, j = (int)vec.size() - 1; i < (int)vec.size(); ++i) {
				while (j >= 0 && vec[i] + vec[j] >= b) {
					--j;
				}
				cnt += (int)vec.size() - max(i + 1, j + 1);
			}
		}

		ans += cnt % 2 * b;
	}

	cout << ans << "\n";

	return 0;
}