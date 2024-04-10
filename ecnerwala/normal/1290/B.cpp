#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string S; cin >> S;
	int N = int(S.size());
	vector<array<int, 26>> V(N+1);
	for (int c = 0; c < 26; c++) {
		V[0][c] = 0;
	}
	for (int i = 0; i < N; i++) {
		for (int c = 0; c < 26; c++) {
			V[i+1][c] = V[i][c] + (S[i]-'a' == c);
		}
	}

	auto query = [&](int l, int r) -> bool {
		assert(r > l);
		if (r - l == 1) return true;

		int cnt = 0;
		for (int c = 0; c < 26; c++) {
			if (V[r][c] - V[l][c]) cnt++;
		}
		assert(cnt);
		if (cnt == 1) {
			return false;
		} else if (cnt == 2) {
			return S[l] != S[r-1];
		} else {
			return true;
		}
	};

	int Q; cin >> Q;
	for (int q = 0; q < Q; q++) {
		int l, r; cin >> l >> r; l--;
		bool ans = query(l, r);
		cout << (ans ? "Yes" : "No") << '\n';
	}

	return 0;
}