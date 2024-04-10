#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	if (N % 2 == 0) {
		N /= 2;
		cout << (N+1) * (N+1) << '\n';
	} else {
		cout << 2 * (N/2+1) * (N/2+2) << '\n';
	}

	return 0;
}