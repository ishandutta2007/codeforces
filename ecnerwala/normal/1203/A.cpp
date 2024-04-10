#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> P(N);
		for (int i = 0; i < N; i++) { cin >> P[i]; P[i] -= 2; }
		vector<int> Q;
		Q.reserve(N);
		for (int i = 0; i < N; i++) {
			if (P[i] == -1) {
				Q.insert(Q.end(), P.begin() + i+1, P.end());
				Q.insert(Q.end(), P.begin(), P.begin() + i);
				break;
			}
		}
		bool incr = true;
		bool decr = true;
		for (int i = 0; i < N-1; i++) {
			incr = incr && (Q[i] == i);
			decr = decr && (Q[i] == N-1-1-i);
		}
		cout << ((incr || decr) ? "YES" : "NO") << '\n';
	}

	return 0;
}