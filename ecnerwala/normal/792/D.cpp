#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int64_t N; int Q; cin >> N >> Q;
	while (Q--) {
		int64_t v; cin >> v;
		string s; cin >> s;
		for (char c : s) {
			int level = __builtin_ctzll(v);
			if (c == 'U') {
				if (v != (N+1)/2) {
					v = (v ^ (1ll << level)) | (1ll << (level+1));
				}
			} else if (c == 'L') {
				if (level > 0) {
					v -= (1ll << (level-1));
				}
			} else if (c == 'R') {
				if (level > 0) {
					v += (1ll << (level-1));
				}
			} else assert(false);
		}
		cout << v << '\n';
	}

	return 0;
}