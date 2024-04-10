#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		int N = int(S.size());
		if (N == 2) cout << S[1] << '\n';
		else {
			cout << *std::min_element(S.begin(), S.end()) << '\n';
		}
	}

	return 0;
}