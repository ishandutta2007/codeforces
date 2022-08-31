#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;
	int best = -1;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		if (a > best + 1) {
			cout << i+1 << '\n';
			return 0;
		} else {
			best = max(best, a);
		}
	}
	cout << -1 << '\n';

	return 0;
}