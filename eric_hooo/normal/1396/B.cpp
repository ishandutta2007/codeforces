#include <bits/stdc++.h>
using namespace std;

int a[110];

int main () {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int k = -1, cnt = 0;
		while (1) {
			int p = -1;
			for (int i = 0; i < n; i++) {
				if (i == k || a[i] == 0) continue;
				if (p == -1 || a[i] > a[p]) p = i;
			}
			if (p == -1) {
				if (cnt) cout << "T" << endl;
				else cout << "HL" << endl;
				break;
			}
			a[p]--, cnt ^= 1, k = p;
		}
	}
	return 0;
}