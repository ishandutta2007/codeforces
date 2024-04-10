#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
		int N;
		cin >> N;
		int i;
		int a;
		int p1, p2;
		p1 = p2 = 0;
		for (i = 1; i <= N; i++) {
			cin >> a;
			if (a == 1) p1++;
			else p2++;
		}
		if (p1 % 2 != 0) cout << "NO" << endl;
		else if (p2 % 2 == 0) {
			cout << "YES" << endl;
		}
		else {
			if (p1 >= 2) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}