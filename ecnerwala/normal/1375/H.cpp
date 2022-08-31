#include<bits/stdc++.h>

namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int AN, Q; cin >> AN >> Q;
	vector<int> A(AN); for (int& a : A) cin >> a, a--;

	const int N = 1 << 12;
	vector<vector<int>> ch(2*N, vector<int>({0}));
	for (int i = 0; i < AN; i++) {
		ch[N+A[i]].push_back(i); // hehe hack to store it
		for (int a = (N+A[i])/2; a; a /= 2) {
			ch[a].push_back(int(ch[2*a+0].size())-1);
		}
	}

	vector<array<int, 2>> root_queries(Q);
	for (int q = 0; q < Q; q++) {
		int l, r; cin >> l >> r; l--;
		root_queries[q] = {l, r};
	}

	int cnt = AN;
	vector<array<int, 2>> ops;
	auto combine = [&](int a, int b) -> int {
		if (a == -1) return b;
		if (b == -1) return a;
		ops.push_back({a, b});
		return cnt++;
	};
	vector<int> ans = std::y_combinator([&](auto self, int a, vector<array<int, 2>> queries) -> vector<int> {
		vector<int> resp(queries.size());
		if (a >= N) {
			for (int q = 0; q < int(queries.size()); q++) {
				resp[q] = (queries[q][0] == queries[q][1] ? -1 : ch[a][1]);
			}
		} else {
			const int L = int(ch[a].size());
			vector<int> st(L);
			for (int q = 0; q < int(queries.size()); q++) {
				st[queries[q][1]]++;
			}
			for (int i = 0; i+1 < L; i++) {
				st[i+1] += st[i];
			}

			vector<int> hi_inds(queries.size());
			for (int q = 0; q < int(queries.size()); q++) {
				hi_inds[--st[queries[q][1]]] = q;
			}

			fill(st.begin(), st.end(), 0);
			for (int q = 0; q < int(queries.size()); q++) {
				st[queries[q][0]]++;
			}
			for (int i = 0; i+1 < L; i++) {
				st[i+1] += st[i];
			}

			vector<int> inds(queries.size());
			for (int q : hi_inds) {
				inds[--st[queries[q][0]]] = q;
			}

			vector<array<int, 2>> distinct_queries;
			distinct_queries.reserve(queries.size());
			{
				array<int, 2> prv{-1, -1};
				for (int q : inds) {
					if (queries[q][0] == queries[q][1]) continue;
					if (queries[q] != prv) {
						prv = queries[q];
						distinct_queries.push_back(queries[q]);
					}
				}
			}

			vector<int> distinct_resp;
			for (int z : {0, 1}) {
				vector<array<int, 2>> nqueries; nqueries.reserve(distinct_queries.size());
				for (auto q : distinct_queries) {
					array<int, 2> nq;
					for (int x : {0, 1}) nq[x] = z ? q[x] - ch[a][q[x]] : ch[a][q[x]];
					nqueries.push_back(nq);
				}

				vector<int> ch_resp = self(2 * a + z, std::move(nqueries));
				if (z) {
					for (int x = 0; x < int(ch_resp.size()); x++) {
						distinct_resp[x] = combine(distinct_resp[x], ch_resp[x]);
					}
				} else {
					distinct_resp = std::move(ch_resp);
				}
			}

			{
				auto qit = distinct_queries.begin();
				auto rit = distinct_resp.begin();
				for (int q : inds) {
					if (queries[q][0] == queries[q][1]) {
						resp[q] = -1;
						continue;
					}
					if (queries[q] != *qit) {
						++qit;
						++rit;
						assert(queries[q] == *qit);
					}
					resp[q] = *rit;
				}
			}
		}
		return resp;
	})(1, std::move(root_queries));

	cout << cnt << '\n';
	for (auto op : ops) cout << op[0]+1 << ' ' << op[1]+1 << '\n';
	for (int q = 0; q < Q; q++) {
		cout << ans[q]+1 << " \n"[q+1==Q];
	}

	return 0;
}