#include<bits/stdc++.h>
using namespace std;

void go() {
	int N, K; cin >> N >> K;
	string S; cin >> S;
	string T;
	for (int i = 0; i < K-1; i++) {
		T += "()";
	}
	for (int i = 0; i < N/2-K+1; i++) {
		T += '(';
	}
	for (int i = 0; i < N/2-K+1; i++) {
		T += ')';
	}

	vector<pair<int, int>> ops;
	for (int i = 0; i < N; i++) {
		if (S[i] == T[i]) continue;
		for (int j = i+1; j < N; j++) {
			if (S[j] == T[i]) {
				ops.push_back({i,j});
				swap(S[i], S[j]);
				break;
			}
		}
	}
	cout << ops.size() << '\n';
	for (auto it : ops) {
		cout << it.first+1 << ' ' << it.second+1 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		go();
	}

	return 0;
}