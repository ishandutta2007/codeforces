#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> P(N);
		for (int i = 0; i < N; i++) {
			cin >> P[i]; P[i]--;
		}
		bool good = true;
		int curMin = N;
		for (int i = 0; i < N; i++) {
			if (P[i] < curMin) {
				curMin = P[i];
			} else if (P[i] == P[i-1]+1) {
				// still good
			} else {
				good = false;
				break;
			}
		}
		cout << (good ? "Yes" : "No") << '\n';
	}

	return 0;
}