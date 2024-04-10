#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		for (int i = 1; i <= N; i++) cout << ((N+i)<<1) << '\n';
	}

	return 0;
}