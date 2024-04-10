#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	string S; cin >> S;
	int N = int(S.size());
	S += S;

	int res = 0;
	for (int z = 0; z < 2; z++) {
		int cnt = 0;
		for (size_t i = 0; i < S.size(); i++) {
			if (("bw"[i&1]==S[i]) == z) {
				cnt++;
				res = max(res, cnt);
			} else {
				cnt = 0;
			}
		}
	}

	res = min(res, N);
	cout << res << '\n';

	return 0;
}