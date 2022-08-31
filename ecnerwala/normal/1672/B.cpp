#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		bool good = S.back() == 'B';
		int v = 0;
		for (char c : S) {
			if (c == 'A') v++;
			else if (c == 'B') {
				v--;
				if (v < 0) good = false;
			}
		}
		cout << (good ? "YES" : "NO") << '\n';
	}

	return 0;
}