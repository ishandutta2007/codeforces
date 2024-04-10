#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	int K; cin >> K;

	string S; cin >> S;

	int numInversions = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (S[i] == 'R' && S[j] == 'L') {
				numInversions++;
			}
		}
	}

	if (K > numInversions) {
		cout << -1 << '\n';
		exit(0);
	}

	set<int> possOps;
	for (int i = 0; i+1 < N; i++) {
		if (S[i] == 'R' && S[i+1] == 'L') {
			possOps.insert(i);
		}
	}

	vector<vector<int>> ops(K);

	for (int k = 0; k < K; k++) {
		auto it = possOps.begin();
		while (it != possOps.end() && numInversions >= K-k) {
			ops[k].push_back(*it);
			numInversions--;
			++it;
		}
		possOps.erase(possOps.begin(), it);

		for (int i : ops[k]) {
			assert(S[i] == 'R' && S[i+1] == 'L');
			swap(S[i], S[i+1]);
		}

		for (int i : ops[k]) {
			assert(S[i] == 'L' && S[i+1] == 'R');
			if (i > 0 && S[i-1] == 'R') possOps.insert(i-1);
			if (i+2 < N && S[i+2] == 'L') possOps.insert(i+1);
		}
	}

	if (numInversions) {
		cout << -1 << '\n';
		exit(0);
	}

	for (int i = 0; i < K; i++) {
		cout << int(ops[i].size()) << ' ';
		for (auto it : ops[i]) cout << it+1 << ' ';
		cout << '\n';
	}

	return 0;
}