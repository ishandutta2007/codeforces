/*input
8



*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n;
	cin >> n;
	long long ats = 0;

	for (int i = 0; i <= 40; i++) {
		ats += n / (1ll << (i + 1)) * (1ll << i);

		if (n % (1ll << (i + 1)) > (1ll << i))
			ats += (1ll << i);
	}

	cout << ats << endl;
	return 0;
}