/*input

3 47 0 4 9
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;

	if (h == 12)
		h = 0;

	if (t1 == 12)
		t1 = 0;

	if (t2 == 12)
		t2 = 0;

	h = h * 3600 + m * 60 + s;
	m = m * 12 * 60 + s * 12;
	s = s * 12 * 60;

	t1 *= 3600;
	t2 *= 3600;

	//cout << h << " " << m << " " << s << " " << t1 << " " << t2 << endl;

	bool ar1 = true;

	for (int i = (t1 + 1) % 43200; i != t2; i = (i + 1) % 43200) {
		if (h == i or m == i or s == i)
			ar1 = false;
	}

	bool ar2 = true;

	for (int i = (t1 + 43200 - 1) % 43200; i != t2; i = (i + 43200 - 1) % 43200) {
		if (h == i or m == i or s == i)
			ar2 = false;
	}

	cout << (ar1 or ar2 ? "YES" : "NO");

	return 0;
}