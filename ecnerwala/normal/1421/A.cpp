#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int a, b; cin >> a >> b;
		cout << (a ^ b) << '\n';
	}

	return 0;
}