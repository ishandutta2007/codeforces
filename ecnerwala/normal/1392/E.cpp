#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << (int64_t(i&1) << (i+j)) << " \n"[j+1==N];
		}
	}
	cout << flush;
	int Q; cin >> Q;
	while (Q--) {
		int64_t K; cin >> K;
		int x = 0, y = 0;
		cout << x+1 << ' ' << y+1 << '\n';
		for (int s = 1; s <= (N-1)+(N-1); s++) {
			if (((x+1)&1) == ((K >> s)&1)) {
				x++;
			} else {
				y++;
			}
			cout << x+1 << ' ' << y+1 << '\n';
		}
		cout << flush;
	}

	return 0;
}