#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string A, B; cin >> A >> B;
		vector<int> ops; ops.reserve(2*N);
		bool flipped = false;
		int lo = 0, hi = N-1;
		for (int i = N-1; i >= 0; i--) {
			if ((flipped ? (A[hi]^1) : A[lo]) == B[i]) {
				ops.push_back(1);
			}
			ops.push_back(i+1);
			if (flipped) {
				hi--;
			} else {
				lo++;
			}
			flipped ^= 1;
		}

		cout << ops.size();
		for (int op : ops) cout << ' ' << op;
		cout << '\n';
	}

	return 0;
}