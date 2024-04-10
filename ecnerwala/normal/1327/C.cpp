#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	cout << (N-1) + (M-1) + N*M << '\n';
	cout << string(N-1, 'U') << string(M-1, 'L');
	for (int i = 0; i < N; i++) {
		cout << string(M-1, "RL"[i&1]);
		cout << 'D';
	}
	cout << '\n';

	return 0;
}