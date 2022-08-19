#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	if (N % 2 == 0) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		for (int i = 0; i < 2 * N; i++) {
			cout << ((i % N) * 2 + (i % 2) + 1) << " \n"[i+1 == 2*N];
		}
	}

	return 0;
}