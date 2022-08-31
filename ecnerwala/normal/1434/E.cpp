#include<bits/stdc++.h>

template <typename T> T& setmax(T& a, const T& b) { if (b > a) a = b; return a; }
template <typename T> T& setmin(T& a, const T& b) { if (b < a) a = b; return a; }

int get_nimber(std::vector<int> A) {
	using namespace std;

	//cerr << "START" << '\n';
	//for (auto a : A) { cerr << a << ' '; } cerr << '\n';
	
	assert(std::is_sorted(A.begin(), A.end()));

	// find the maximum convex subsequence
	int N = int(A.size());

	set<int> step_0;
	const int MAXL = 500;
	vector<priority_queue<int>> min_first(MAXL+1);
	vector<int> val(N);
	vector<vector<int>> to_insert(N);
	vector<int> cutoffs; cutoffs.reserve(MAXL+1);

	for (int i = N-1; i >= 0; i--) {
		cutoffs.clear();
		for (int l = 0; l <= MAXL; l++) {
			while (!min_first[l].empty() && val[min_first[l].top()] != l) {
				min_first[l].pop();
			}
			if (min_first[l].empty()) {
				break;
			}
			assert(l+1 <= MAXL);
			int nv = 2 * A[i] - A[min_first[l].top()];
			assert(nv < A[i]);
			int j = int(upper_bound(A.begin(), A.end(), nv) - A.begin());
			assert(j <= i);
			cutoffs.push_back(j);
		}
		int V = int(cutoffs.size());
		step_0.insert(V);

		val[i] = V;
		min_first[V].push(i);
		for (int v = 1; v < V; v++) {
			cutoffs[v] = max(cutoffs[v-1], cutoffs[v]);
		}
		for (int v = V-1; v >= 0; v--) {
			to_insert[cutoffs[v]].push_back(i);
		}

		for (auto a : to_insert[i]) {
			val[a]--;
			min_first[val[a]].push(a);
		}
	}

	int ans = 0;
	while (step_0.count(ans)) ans++;
	//cerr << "Answer " << ans << '\n';
	return ans;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	int ans = 0;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N);
		for (auto& a : A) cin >> a;
		ans ^= get_nimber(std::move(A));
	}
	cout << (ans != 0 ? "YES" : "NO") << '\n';

	return 0;
}