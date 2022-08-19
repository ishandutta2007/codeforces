#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int> A(N); for (auto& a : A) { cin >> a; a--; }
	int M = *max_element(A.begin(), A.end())+1;

	vector<int> cnt(M);
	vector<vector<int>> locs(M);
	for (int i = 0; i < N; i++) {
		cnt[A[i]]++;
		locs[A[i]].push_back(i);
	}

	int V = int(max_element(cnt.begin(), cnt.end()) - cnt.begin());
	vector<int> prefV(N+1);
	for (int i = 0; i < N; i++) {
		prefV[i+1] = prefV[i] + (A[i] == V);
	}

	int mi = 0;
	int ma = N+1;

	{
		vector<pair<int, int>> stk; stk.reserve(N);
		for (int u = 0; u < M; u++) {
			if (u == V) continue;
			stk.clear();
			for (int z = 0; z < int(locs[u].size()); z++) {
				{
					int cnd = z - prefV[locs[u][z]];
					if (stk.empty() || cnd < stk.back().first) stk.push_back({cnd, locs[u][z]});
				}
				{
					int cnd = (z+1) - prefV[locs[u][z]+1];
					int lo = -1, hi = int(stk.size());
					while (hi - lo > 1) {
						int md = lo + (hi - lo) / 2;
						if (cnd >= stk[md].first) hi = md;
						else lo = md;
					}
					assert(hi < int(stk.size()));
					mi = max(mi, locs[u][z]+1 - stk[hi].second);
				}
			}
		}
	}

	auto is_good = [&](int L) -> bool {
		if (L == 0) return true;
		assert(L >= 1);

		vector<int> cnt(M);
		vector<int> cnt_cnt(N+1);
		cnt_cnt[0] = M;

		for (int l = 0, r = 0; l <= N-L; ) {
			while (r < l+L) {
				cnt_cnt[cnt[A[r]]]--;
				cnt[A[r]]++;
				cnt_cnt[cnt[A[r]]]++;
				r++;
			}

			int max_test = l == 0 ? N : min(N, cnt[V]+1);
			if (std::accumulate(cnt_cnt.begin() + cnt[V], cnt_cnt.begin() + max_test+1, int(0)) >= 2) {
				return true;
			}

			cnt_cnt[cnt[A[l]]]--;
			cnt[A[l]]--;
			cnt_cnt[cnt[A[l]]]++;
			l++;
		}
		return false;
	};

	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		if (is_good(md)) {
			mi = md;
		} else {
			ma = md;
		}
	}

	cout << mi << '\n';

	return 0;
}