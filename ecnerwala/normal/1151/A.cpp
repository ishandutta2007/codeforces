#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	string S; cin >> S;
	int res = int(1e9);
	for (int i = 0; i + 4 <= N; i++) {
		int cnd = 0;
		for (int z = 0; z < 4; z++) {
			int v = "ACTG"[z] - S[i+z];
			v %= 26;
			if (v < 0) v += 26;
			cnd += min(v, 26-v);
		}
		res = min(res, cnd);
	}
	cout << res << '\n';

	return 0;
}