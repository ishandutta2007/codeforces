#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; int64_t T; cin >> N >> T;
	string S; cin >> S;

	T -= int64_t(1) << (S.back() - 'a');
	S.pop_back();
	T += int64_t(1) << (S.back() - 'a');
	S.pop_back();

	array<int, 80> cnt; cnt.fill(0);
	for (char c : S) {
		T += int64_t(1) << (c - 'a');
		cnt[c - 'a' + 1] ++;
	}

	cout << ([&]() -> bool {
		if (T < 0) return false;
		for (int i = 0; T > 0; i++) {
			if (T & 1) {
				if (!cnt[i]) return false;
				cnt[i]--;
				T--;
			}
			T >>= 1;
			cnt[i+1] += cnt[i] >> 1;
		}
		assert(T == 0);
		return true;
	}() ? "Yes" : "No") << '\n';

	return 0;
}