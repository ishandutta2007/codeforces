#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		string S, C; cin >> S >> C;
		for (int i = 0; i < int(S.size()); i++) {
			char best = *min_element(S.begin()+i, S.end());
			if (best == S[i]) continue;
			for (int j = int(S.size()) - 1; j > i; j--) {
				if (S[j] == best) {
					swap(S[j], S[i]);
					goto done;
				}
			}
		}
done:
		if (S < C) {
			cout << S << '\n';
		} else {
			cout << "---" << '\n';
		}
	}

	return 0;
}