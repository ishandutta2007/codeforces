#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	vector<int64_t> A(N); for (auto& v : A) cin >> v;
	vector<int> B(N); for (auto& v : B) { cin >> v; if (v != -1) v--; }
	vector<int> indeg(N);
	for (int i = 0; i < N; i++) {
		if (B[i] != -1) {
			indeg[B[i]]++;
		}
	}

	vector<int> pref; pref.reserve(N);
	vector<int> suff; suff.reserve(N);

	vector<int> q; q.reserve(N);
	for (int i = 0; i < N; i++) {
		if (!indeg[i]) q.push_back(i);
	}

	int64_t ans = 0;

	for (int z = 0; z < int(q.size()); z++) {
		int cur = q[z];
		ans += A[cur];
		if (A[cur] >= 0) {
			pref.push_back(cur);
			if (B[cur] != -1) A[B[cur]] += A[cur];
		} else {
			suff.push_back(cur);
		}
		if (B[cur] != -1) {
			if (!--indeg[B[cur]]) q.push_back(B[cur]);
		}
	}
	assert(int(q.size()) == N);

	pref.insert(pref.end(), suff.rbegin(), suff.rend());

	cout << ans << '\n';
	for (int i = 0; i < N; i++) {
		cout << pref[i]+1 << " \n"[i+1==N];
	}

	return 0;
}