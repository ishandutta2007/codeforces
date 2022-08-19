#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	if (N == 1) {
		cout << 0 << '\n';
		exit(0);
	}
	int L = 1 << (31 - __builtin_clz(N-1));
	assert(L < N);
	assert(L + L >= N);

	vector<array<int, 2>> ans; ans.reserve(int(5.1e5));
	for (int z = 0; z < 2; z++) {
		int offset = z ? N-L : 0;
		for (int d = 1; d < L; d *= 2) {
			for (int i = 0; i < L; i++) {
				if (i & d) continue;
				ans.push_back({offset + i, offset + (i | d)});
			}
		}
	}

	cout << ans.size() << '\n';
	for (const auto& a : ans) {
		cout << a[0]+1 << ' ' << a[1]+1 << '\n';
	}

	return 0;
}