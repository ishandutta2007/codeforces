#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		cout << string(3*N/4, '9') << string((N+3)/4, '8') << '\n';
	}
	return 0;
}