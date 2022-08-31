#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, A, B, C; cin >> N >> A >> B >> C;
		string S; cin >> S;
		string T(N, ' ');
		for (int i = 0; i < N; i++) {
			char c = S[i];
			if (c == 'R') {
				if (B) T[i] = 'P', B--;
			} else if (c == 'P') {
				if (C) T[i] = 'S', C--;
			} else if (c == 'S') {
				if (A) T[i] = 'R', A--;
			} else assert(false);
		}
		if ((N - (A + B + C)) * 2 >= N) {
			cout << "YES" << '\n';
			for (int i = 0; i < N; i++) {
				if (T[i] == ' ') {
					if (A) T[i] = 'R', A--;
					else if (B) T[i] = 'P', B--;
					else if (C) T[i] = 'S', C--;
					else assert(false);
				}
			}
			cout << T << '\n';
		} else {
			cout << "NO" << '\n';
		}
	}

	return 0;
}