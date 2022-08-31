#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		int N = int(S.size());
		int X; cin >> X;

		string W(N, '\0');
		for (int i = 0; i < N; i++) {
			W[i] = (i-X < 0 || S[i-X] == '1') && (i+X >= N || S[i+X] == '1') ? '1' : '0';
		}
		bool is_good = true;
		for (int i = 0; i < N; i++) {
			if (((i-X >= 0 && W[i-X] == '1') || (i+X < N && W[i+X] == '1') ? '1' : '0') != S[i]) is_good = false;
		}
		if (is_good) {
			cout << W << '\n';
		} else {
			cout << -1 << '\n';
		}
	}

	return 0;
}