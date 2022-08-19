#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	string S; cin >> S;
	for (int z = 0; z < 2; z++) {
		vector<int> V(N);
		for (int i = 0; i < N; i++) {
			V[i] = S[i] == 'W';
		}
		vector<int> ans;
		if (z) {
			V[0] ^= 1;
			V[1] ^= 1;
			ans.push_back(1);
		}
		for (int i = 1; i+1 < N; i++) {
			if (V[i] != V[i-1]) {
				V[i] ^= 1;
				V[i+1] ^= 1;
				ans.push_back(i+1);
			}
		}
		if (V[N-2] != V[N-1]) {
			continue;
		}
		cout << ans.size() << '\n';
		for (int i = 0; i < int(ans.size()); i++) {
			cout << ans[i] << " \n"[i+1==int(ans.size())];
		}
		exit(0);
	}
	cout << -1 << '\n';

	return 0;
}