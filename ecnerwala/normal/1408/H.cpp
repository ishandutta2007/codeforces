#include<bits/stdc++.h>

int go(std::vector<int> A) {
	using namespace std;
	int N = int(A.size());
	vector<vector<int>> locs(N, vector<int>({0}));
	int tot_bad = 0;
	for (int i = N-1; i >= 0; i--) {
		if (A[i] == -1) tot_bad++;
		else {
			locs[A[i]].push_back(tot_bad);
		}
	}
	struct seg_node {
		int val = 0;
		int lazy = 0;
	};
	vector<seg_node> seg(2*N);
	auto update_node = [&](int a) {
		assert(a < N);
		seg[a].val = min(seg[2*a].val, seg[2*a+1].val);
		seg[a].val += seg[a].lazy;
	};
	auto update_all = [&](int a) {
		a >>= __builtin_ctz(a);
		a >>= 1;
		for (; a; a /= 2) update_node(a);
	};

	for (int i = 0; i < N; i++) {
		seg[N+i].val = i;
		seg[N+i].lazy = 0;
	}
	for (int a = N-1; a; a--) update_node(a);

	auto incr = [&](int x, int y, int v) {
		if (x >= y) return;
		for (int a = N+x, b = N+y; a < b; a >>= 1, b >>= 1) {
			if (a & 1) { seg[a].val += v, seg[a].lazy += v; a++; }
			if (b & 1) { --b; seg[b].val += v, seg[b].lazy += v; }
		}
		update_all(N+x);
		update_all(N+y);
	};

	for (int v = 0; v < N; v++) {
		incr(0, locs[v].back(), +1);
	}

	int ans = min(N/3, tot_bad/2);
	int l_cnt = 0;
	for (int v : A) {
		if (v == -1) {
			ans = min(ans, l_cnt + seg[1].val);
			l_cnt++;
		} else {
			assert(!locs[v].empty());
			int x = locs[v].back();
			locs[v].pop_back();
			incr(locs[v].back(), x, -1);
		}
	}

	return ans;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> A(N); for (auto& a : A) { cin >> a; a--; }
		int ans = go(std::move(A));
		cout << ans << '\n';
	}

	return 0;
}