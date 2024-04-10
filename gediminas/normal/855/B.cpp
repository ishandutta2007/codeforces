/*input
5 1000000000 1000000000 1000000000
-1000000000 -1000000000 -1000000000 -1000000000 -1000000000

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	long long p[3];
	cin >> n >> p[0] >> p[1] >> p[2];
	long long a[n];

	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<long long> m, d;

	for (int i = 0; i < 3; i++) {
		if (p[i] < 0)
			m.push_back(p[i]);
		else
			d.push_back(p[i]);
	}

	long long ats = -3000000000000000030ll;
	long long s1 = -1000000000000000010ll;
	long long s2 = -2000000000000000010ll;

	for (int i = 0; i < n; i++) {
		s1 = max(s1, a[i] * p[0]);
		s2 = max(s1 + a[i] * p[1], s2);
		ats = max(s2 + a[i] * p[2], ats);
	}

	cout << ats;


	return 0;
}