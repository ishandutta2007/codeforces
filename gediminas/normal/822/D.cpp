/*input
2 2 4

*/
#include <bits/stdc++.h>

using namespace std;

long long sudet[5000005];
long long din[5000005];

int main () {

	vector<long long> pirm;

	for (long long i = 2; i <= 5000000; i++) {
		if (sudet[i] == 0) {
			for (long long j = i; j <= 5000000; j += i) {
				if (sudet[j] == 0)
					sudet[j] = i;
			}
		}
	}

	for (long long i = 2; i <= 5000000; i++)
		din[i] = (i * (sudet[i] - 1) / 2 + din[i / sudet[i]]) % 1000000007ll;

	long long t, l, r;
	cin >> t >> l >> r;
	long long ats = 0;
	long long daug = 1;

	for (long long i = l; i <= r; i++) {
		ats += (daug * din[i]) % 1000000007ll;
		ats %= 1000000007ll;
		daug = (daug * t) % 1000000007ll;
	}

	cout << ats;

	return 0;
}