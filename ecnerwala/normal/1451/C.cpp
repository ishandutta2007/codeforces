#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		string A, B; cin >> A >> B;
		bool ans = [&]() -> bool {
			array<int, 26> CA;
			array<int, 26> CB;
			fill(CA.begin(), CA.end(), 0);
			fill(CB.begin(), CB.end(), 0);
			for (char c : A) CA[c-'a']++;
			for (char c : B) CB[c-'a']++;
			for (int i = 0; i < 26; i++) {
				if (CA[i] < CB[i]) return false;
				if (CA[i] % K != CB[i] % K) return false;
				if (CA[i] > CB[i]) {
					CA[i+1] += CA[i] - CB[i];
				}
			}
			return true;
		}();
		cout << (ans ? "Yes" : "No") << '\n';
	}

	return 0;
}