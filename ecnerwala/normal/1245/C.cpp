#include<bits/stdc++.h>
using namespace std;

const int MOD = int(1e9)+7;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string S; cin >> S;
	int v = 1, v1 = 0;
	for (int i = 0; i < int(S.size()); i++) {
		if (S[i] == 'm' || S[i] == 'w') {
			cout << 0 << '\n';
			exit(0);
		}
		if (i && S[i] == S[i-1] && (S[i] == 'n' || S[i] == 'u')) {
			v += v1;
			v1 = v - v1;
			if (v >= MOD) v -= MOD;
		} else {
			v1 = v;
		}
	}
	cout << v << '\n';

	return 0;
}