#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> ltaken(N), rtaken(N);
		for (int i = 0; i < N; i++) {
			int K; cin >> K;
			while (K--) {
				int j; cin >> j; j--;
				if (!ltaken[i] && !rtaken[j]) {
					ltaken[i] = rtaken[j] = true;
				}
			}
		}
		int a = int(find(ltaken.begin(), ltaken.end(), false) - ltaken.begin());
		int b = int(find(rtaken.begin(), rtaken.end(), false) - rtaken.begin());
		if (a == N) {
			cout << "OPTIMAL" << '\n';
		} else {
			cout << "IMPROVE" << '\n';
			cout << a+1 << ' ' << b+1 << '\n';
		}
	}

	return 0;
}