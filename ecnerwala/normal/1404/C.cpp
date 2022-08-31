#include<bits/extc++.h>

template <typename K, typename V, typename Comp = std::less<K>>
using order_statistic_map = __gnu_pbds::tree<
	K, V, Comp,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update
>;

template <typename K, typename Comp = std::less<K>>
using order_statistic_set = order_statistic_map<K, __gnu_pbds::null_type, Comp>;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	vector<int> A(N); for (auto& a : A) cin >> a, a--;

	vector<int> ans(Q);
	vector<vector<pair<int, int>>> queries_by_right(N);
	for (int q = 0; q < Q; q++) {
		int x, y; cin >> x >> y;
		queries_by_right[N-1-y].push_back({x, q});
	}

	// For each element of A, it requires a certain starting point to be removed
	order_statistic_set<pair<int, int>, greater<pair<int, int>>> remove_time_set;
	for (int i = 0; i < N; i++) {
		if (A[i] > i) {
			// do nothing
		} else if (A[i] == i) {
			remove_time_set.insert(pair<int, int>(i, i));
		} else {
			int num_prev_remove = i - A[i];
			assert(num_prev_remove > 0);
			if (num_prev_remove <= int(remove_time_set.size())) {
				int remove_time = remove_time_set.find_by_order(num_prev_remove - 1)->first;
				remove_time_set.insert(pair<int, int>(remove_time, i));
			}
		}

		for (auto [x, q] : queries_by_right[i]) {
			assert(x <= i);
			ans[q] = int(remove_time_set.order_of_key(pair<int, int>(x, -1)));
		}
	}

	for (int q = 0; q < Q; q++) {
		cout << ans[q] << '\n';
	}

	return 0;
}