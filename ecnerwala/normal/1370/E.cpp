#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	string S, T; cin >> S >> T;
	int c[2] = {0,0};
	int tot = 0;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] != T[i]) {
			int z = S[i] & 1;
			tot += (z ? 1 : -1);
			if (!c[z]) {
				ans++;
				c[z]++;
			}
			c[z]--;
			c[!z]++;
		}
	}

	if (tot) ans = -1;
	cout << ans << '\n';

	return 0;
}