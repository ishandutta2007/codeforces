#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int Q; cin >> Q;
	while (Q--) {
		int N; cin >> N;
		vector<int> A(N);
		for (auto& a : A) cin >> a;
		sort(A.begin(), A.end());
		A.erase(unique(A.begin(), A.end()), A.end());
		N = int(A.size());

		vector<vector<int>> buckets(32);
		for (auto a : A) {
			buckets[__builtin_clz(a)].push_back(a);
		}
		for (int i = 0; i < 32; i++) {
			sort(buckets[i].begin(), buckets[i].end(), std::greater());
		}

		int ans = *std::max_element(A.begin(), A.end());
		for (int i = 0; i < 32; i++) {
			if (buckets[i].size() >= 3) {
				buckets[i].resize(3);
				ans = max(ans, buckets[i][0] + buckets[i][1] + buckets[i][2]);
				break;
			} else {
				for (int a : buckets[i]) {
					for (int j = i; j < 32; j++) {
						int last_good = -1;
						for (int b : buckets[j]) {
							if (b >= a) continue;
							assert(a > b);
							if (a % b == 0) continue;
							if (last_good != -1) {
								assert(last_good % b != 0);
								ans = max(ans, a + last_good + b);
								break;
							}
							ans = max(ans, a + b);
							last_good = b;
							for (int k = j+1; k < 32; k++) {
								for (int c : buckets[k]) {
									assert(c < b && b < a);
									if (a % c == 0 || b % c == 0) continue;
									ans = max(ans, a + b + c);
								}
							}
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}