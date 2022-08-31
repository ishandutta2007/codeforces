#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> cur; cur.reserve(N);
		while (N--) {
			int a; cin >> a;
			if (a == 1) {
				cur.push_back(1);
			} else {
				while (cur.back() != a-1) cur.pop_back();
				cur.back()++;
			}
			for (int z = 0; z < int(cur.size()); z++) {
				cout << cur[z] << ".\n"[z+1==int(cur.size())];
			}
		}
	}

	return 0;
}