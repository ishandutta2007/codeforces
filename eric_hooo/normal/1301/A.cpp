#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		string a, b, c; cin >> a >> b >> c;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i]) {
				if (a[i] != c[i]) {
					printf("NO\n");
					goto END;
				}
			} else {
				if (a[i] != c[i] && b[i] != c[i]) {
					printf("NO\n");
					goto END;
				}
			}
		}
		printf("YES\n");
		END:;
	}
	return 0;
}