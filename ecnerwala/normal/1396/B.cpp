#include<bits/stdc++.h>
#include <numeric>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (auto& a : A) cin >> a;

		bool winning = [&]() -> bool {
			int tot = std::accumulate(A.begin(), A.end(), 0);
			int mx = *std::max_element(A.begin(), A.end());

			if (mx * 2 <= tot) {
				return tot % 2 == 1;
			}

			// If there is a (weak) majority and you don't take it, the 2nd player can keep taking that and win
			// => must start off by taking from the majority
			// If that's still a (weak) majority, you win

			assert(mx * 2 > tot);
			return true;
		}();
		
		cout << (winning ? "T" : "HL") << '\n';
	}

	return 0;
}