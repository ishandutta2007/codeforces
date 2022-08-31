#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int x, y; cin >> x >> y;
		cout << 2*max(x,y)-(x!=y) << '\n';
	}

	return 0;
}