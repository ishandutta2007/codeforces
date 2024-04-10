#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string R; cin >> R;
		string B; cin >> B;
		int num_red = 0;
		for (int i = 0; i < N; i++) {
			if (R[i] > B[i]) num_red++;
			else if (R[i] < B[i]) num_red--;
		}
		if (num_red > 0) cout << "RED" << '\n';
		else if (num_red < 0) cout << "BLUE" << '\n';
		else cout << "EQUAL" << '\n';
	}

	return 0;
}