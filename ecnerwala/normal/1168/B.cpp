#include<bits/stdc++.h>
using namespace std;

string S;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> S;
	int N = int(S.size());
	long long res = 0;
	for (int i = 0; i < N; i++) {
		res += N - i;
		for (int j = i+1; j <= N; j++) {
			for (int x = i; x < j; x++) {
				for (int z = x + 1, y = x + 2; y < j; z += 1, y += 2) {
					if (S[x] == S[z] && S[x] == S[y]) {
						goto found;
					}
				}
			}
			// not found
			res --;
		}
found:
		;
	}
	cout << res << '\n';

	return 0;
}