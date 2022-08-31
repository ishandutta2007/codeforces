#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	while (true) {
		for (int i = 1; i < N; i++) {
			A[i].first -= A[0].first;
			A[i].second -= A[0].second;
		}
		A[0] = {0,0};

		vector<int> inds;
		for (int i = 0; i < N; i++) {
			if ((A[i].first ^ A[i].second) & 1) {
				inds.push_back(i);
			}
		}
		if (!inds.empty()) {
			cout << inds.size() << '\n';
			for (int i = 0; i < int(inds.size()); i++) {
				cout << inds[i]+1 << " \n"[i+1==int(inds.size())];
			}
			exit(0);
		}
		for (int i = 0; i < N; i++) {
			A[i] = pair<int, int>((A[i].first+A[i].second) / 2, (A[i].first - A[i].second) / 2);
		}
	}

	return 0;
}