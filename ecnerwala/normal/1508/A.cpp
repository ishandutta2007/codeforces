#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		array<string, 3> S;
		array<int, 3> cnt{0,0,0};
		array<bool, 3> dir{0,0,0};
		for (int z = 0; z < 3; z++) {
			cin >> S[z];
			for (char c : S[z]) cnt[z] += c - '0';
			dir[z] = (cnt[z] >= N);
		}
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 3; j++) {
				if (dir[i] == dir[j]) {
					char d = dir[i] + '0';
					auto a = S[i].begin(), b = S[j].begin();
					string res; res.reserve(3*N);
					for (int z = 0; z < N; z++) {
						while (*a != d) {
							res += *a;
							++a;
						}
						while (*b != d) {
							res += *b;
							++b;
						}
						res += d;
						++a, ++b;
					}
					res.insert(res.end(), a, S[i].end());
					res.insert(res.end(), b, S[j].end());
					assert(int(res.size()) == 3*N);
					cout << res << '\n';
					goto done;
				}
			}
		}
		assert(false);
done:;
	}

	return 0;
}