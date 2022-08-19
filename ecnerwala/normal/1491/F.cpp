#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	auto query = [&](int lo, int hi, int b) {
		cout << '?' << ' ' << hi-lo << ' ' << 1 << '\n';
		for (int i = lo; i < hi; i++) { cout << i+1 << ' '; } cout << '\n';
		cout << b+1 << '\n' << flush;
		int v; cin >> v;
		return v;
	};

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int i = 1;
		while (query(0, i, i) == 0) i++;

		// now we get the answer
		int lo = 0, hi = i;
		while (hi - lo > 1) {
			int md = (lo + hi) / 2;
			if (query(lo, md, i)) hi = md;
			else lo = md;
		}

		vector<int> ans; ans.reserve(N-2);
		for (int j = 0; j < i; j++) {
			if (j != lo) ans.push_back(j);
		}
		for (int j = i+1; j < N; j++) {
			if (!query(j, j+1, i)) ans.push_back(j);
		}

		cout << '!' << ' ' << ans.size();
		for (int v : ans) { cout << ' ' << v+1; } cout << '\n';
		cout << flush;
	}

	return 0;
}