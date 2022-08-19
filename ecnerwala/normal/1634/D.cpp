#include <bits/stdc++.h>

static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		auto solve = [](int N) -> std::array<int, 2> {
			auto query = [](int a, int b, int c) -> int {
				cout << '?' << ' ' << a << ' ' << b << ' ' << c << '\n' << flush;
				int res; cin >> res;
				return res;
			};

			std::vector<int> inds(N);
			std::iota(inds.begin(), inds.end(), 1);
			std::shuffle(inds.begin(), inds.end(), std::mt19937(FIXED_RANDOM));
			while (true) {
				assert(!inds.empty());
				if (inds.size() == 1) {
					return {inds[0], inds[0]};
				}
				if (inds.size() == 2) {
					return {inds[0], inds[1]};
				}
				assert(inds.size() != 3);
				assert(inds.size() >= 4);
				std::array<std::pair<int, int>, 4> vals;
				{
					int a = inds.back(); inds.pop_back();
					int b = inds.back(); inds.pop_back();
					int c = inds.back(); inds.pop_back();
					int d = inds.back(); inds.pop_back();

					int vd = query(a, b, c);
					int vc = query(a, b, d);
					int vb = query(a, c, d);
					int va = query(b, c, d);

					vals = {{
						{va, a}, {vb, b}, {vc, c}, {vd, d}
					}};
					std::sort(vals.begin(), vals.end());
				}
				int mx = vals[3].first;
				if (vals[0].first == mx) {
					if (inds.size() == 3) {
						inds.push_back(vals[0].second);
					}
					continue;
				} else if (vals[1].first == mx) {
					// find the unique min
					inds.push_back(vals[0].second);
					if (inds.size() == 3) {
						inds.push_back(vals[1].second);
					}
					continue;
				} else if (vals[2].first == mx) {
					// we need to find the 2 that are less than mx
					int a = vals[0].second;
					int d = vals[1].second;
					int b = vals[2].second;

					int l = mx;

					while (!inds.empty()) {
						int e = inds.back(); inds.pop_back();
						int v = query(a, d, e);
						if (v <= l) {
							continue;
						}
						l = v;
						if (query(e, b, d) == l) {
							a = e;
						} else {
							d = e;
						}
					}
					return {a, d};
				} else assert(false);
			}
			assert(false);
		};
		auto ans = solve(N);
		cout << '!' << ' ' << ans[0] << ' ' << ans[1] << '\n' << flush;
	}

	return 0;
}

// On 4 numbers:
// A <= B <= C <= D
// D-A, D-A, C-A, D-B
// we can identify the min as either one missing from C-A or from D-B
// We can't distinguish min vs max (if all distinct)
//
// A < B <= D
// and given E
// Ask A,D,E, if it's <= D-A then we continue with what we have.
// If it's bigger, we need to decide which side to replace.
// So query B,D,E
//
// If our initial set is not distinguishable, then we need some fallback.
// A = B < C = D
// All 4 values are identical, but none can be the 0.
// We could delete them all, but that might leave us with 3 numbers.
// You just add one back in, then it costs 4 queries to delete 3 which is fine.
//
// A < B <= C = D
// Gives 3 identical values, can't distinguish BCD, none of which can be the 0.
// If you are left with 3, then add one back in, costs 4 to delete 2.