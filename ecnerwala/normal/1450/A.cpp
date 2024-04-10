#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string S; cin >> S;
		sort(S.begin(), S.end());
		cout <<S  << '\n';
	}

	return 0;
}