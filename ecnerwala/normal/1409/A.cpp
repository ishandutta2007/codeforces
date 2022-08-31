#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int A, B; cin >> A >> B;
		int D = abs(A-B);
		cout << (D+9) / 10 << '\n';
	}

	return 0;
}