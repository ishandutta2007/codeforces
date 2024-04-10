#include <bits/stdc++.h>

using namespace std;
/*input
4
4
-><-
5
>>>>>
3
<--
2
<>
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		string a;
		cin >> a;
		int cnt = 0;
		bool gera = true, gerb = true;

		for (int i = 0; i < n; ++i) {
			if (a[i] == '-' or a[(i + 1) % n] == '-') {
				cnt++;
			}

			if (a[i] != '-' and a[i] != '>') {
				gera = false;
			}

			if (a[i] != '-' and a[i] != '<') {
				gerb = false;
			}
		}

		if (gera or gerb) {
			cnt = n;
		}

		cout << cnt << "\n";
	}
}