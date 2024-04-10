#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	string S; cin >> S;
	string T; cin >> T;
	int N = int(S.size());
	int M = int(T.size());
	vector<int> A(N);
	for (auto& a : A) cin >> a, a--;
	vector<int> V(N);
	for (int i = 0; i < N; i++) V[A[i]] = i;

	int mi = 0;
	int ma = N+1;
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		int j = 0;
		for (int i = 0; i < N && j < M; i++) {
			if (V[i] >= md && S[i] == T[j]) {
				j++;
			}
		}
		if (j == M) {
			mi = md;
		} else {
			ma = md;
		}
	}
	cout << mi << '\n';

	return 0;
}