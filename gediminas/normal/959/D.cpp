/*input
6
12 4 2 2 2 2
*/
#include <bits/stdc++.h>

using namespace std;

bool negalim[2000001] = {};

void ismesk(int kien) {
	if (negalim[kien])
		return;

	for (int i = kien; i < 2000000; i += kien) {
		negalim[i] = true;
	}

	for (int i = 2; i * i <= kien; i++) {
		if (kien % i == 0) {
			ismesk(i);
			ismesk(kien / i);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	bool did = false;
	int pp = 2;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (did) {
			while (negalim[pp]) {
				pp++;
			}

			cout << pp << " ";
			ismesk(pp);
		}
		else {
			if (!negalim[x]) {
				cout << x << " ";
				ismesk(x);
			}
			else {
				for (int i = x + 1; i < 2000000; i++) {
					if (!negalim[i]) {
						cout << i << " ";
						ismesk(i);
						break;
					}
				}

				did = true;
			}
		}
	}

	return 0;
}