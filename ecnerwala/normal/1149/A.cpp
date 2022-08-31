#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N; cin >> N;
	int c1 = 0, c2 = 0;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		if (a == 1) c1++;
		else if (a == 2) c2++;
	}
	if (c2) {
		cout << 2 << ' ';
		c2--;
	}
	if (c1) {
		cout << 1 << ' ';
		c1--;
	}
	while (c2) {
		cout << 2 << ' ';
		c2--;
	}
	while (c1) {
		cout << 1 << ' ';
		c1--;
	}
	cout << '\n';

	return 0;
}