/*input
12

*/
#include <bits/stdc++.h>

using namespace std;

vector<int> ats;

void rek(long long n) {
	if (n == 0)
		return;

	long long t = (sqrt(8 * n + 1) - 1) / 2;

	if ((t * t + t) / 2 > n)
		t--;

	ats.push_back(t + 1);
	rek(n - (t * t + t) / 2);
}

int main () {
	long long k;
	cin >> k;

	rek(k);

	for (int i = 0; i < ats.size(); i++) {
		for (int j = 0; j < ats[i]; j++)
			cout << (char)('a' + i);
	}

	if (ats.size() == 0)
		cout << "a";

	return 0;
}