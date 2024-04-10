#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T-- > 0) {
		char s1[100], s2[100];
		cin >> s1 >> s2;
		int i;
		int sz1, sz2;
		for (i = 0; s1[i] != NULL; i++);
		sz1 = i;
		for (i = 0; s2[i] != NULL; i++);
		sz2 = i;
		int j;
		for (j = 1; j <= sz1 * sz2; j++) {
			if (j%sz1 == 0 && j%sz2 == 0) break;
		}
		int c = 0;
		for (i = 0; i < j; i++) {
			if (s1[i%sz1] != s2[i%sz2]) c = 1;
		}
		if (c == 1) cout << "-1";
		else {
			for (i = 0; i < j; i++) {
				cout << s1[i%sz1];
			}
		}
		cout << endl;
	}
}