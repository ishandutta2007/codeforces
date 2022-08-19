#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int N, K; cin >> N >> K;
		int i = N-1;
		while (N-1-i < K) {
			K -= N-1-i;
			i--;
		}
		string res(N , 'a');
		res[i] = 'b';
		res[N-K] = 'b';
		cout << res << '\n';
	}

	return 0;
}