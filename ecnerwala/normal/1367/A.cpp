#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		string S; cin >> S;
		string A; A += S[0];
		for (int i = 1; i < int(S.size()); i+=2) {
			A += S[i];
		}
		cout << A << '\n';
	}

	return 0;
}