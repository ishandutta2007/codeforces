#include<bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	if (N == 1) {
		cout << "-1" << '\n';
		return;
	} else if (N % 3 != 1) {
		for (int z = 0; z < N-1; z++) cout << '2';
		cout << '3';
		cout << '\n';
	} else {
		for (int z = 0; z < N-2; z++) cout << '2';
		cout << '3' << '3';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}