/*input

5 -1 2 4
-5 5 25 48
*/
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
	long long b, q, l, m;
	cin >> b >> q >> l >> m;
	set<long long> blog;

	for (int i = 0; i < m; i++) {
		long long x;
		cin >> x;
		blog.insert(x);
	}

	if(llabs(b)>l){
		cout << 0 << endl;
		return 0;
	}

	if (q == 1) {
		if (blog.count(b) > 0)
			cout << 0;
		else
			cout << "inf";

		return 0;
	}
	else if (q == 0) {
		if (blog.count(0) > 0) {
			if (blog.count(b) > 0)
				cout << 0;
			else
				cout << 1;
		}
		else
			cout << "inf";

		return 0;
	}
	else if (q == -1) {
		if (blog.count(b) > 0 and blog.count(-b) > 0)
			cout << 0;
		else
			cout << "inf";

		return 0;
	}
	else if (b == 0) {
		if (blog.count(0) > 0)
			cout << 0;
		else
			cout << "inf";

		return 0;
	}

	long long ats = 0;

	while (llabs(b) <= l) {
		if (blog.count(b) == 0)
			ats++;

		b *= q;
	}

	cout << ats;
	return 0;
}