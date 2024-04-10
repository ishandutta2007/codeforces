#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int x, y; cin >> x >> y;
	vector<long long> a;
	for (int i = 1; i <= 10; ++i)
		for (int j = 0; j < (1 << i); ++j) {
			long long val = 0;
			for (int k = 0; k < i; ++k)
				if ((1 << k) & j)
					val = val * 10 + 7;
				else
					val = val * 10 + 4;
			a.push_back(val);
		}
	
	sort(a.begin(), a.end());
	int p = 0;
	while (a[p] < x)
		++p;
	if (x <= a[p] && y <= a[p]) {
		cout << (1LL * (y - x + 1) * a[p]);
		return 0;
	}
	long long rez = 1LL * (a[p] - x + 1) * a[p];
	++p;
	while (a[p] <= y) {
		rez += 1LL * (a[p] - a[p - 1]) * a[p];
		++p;
	}

	rez += 1LL * (y - a[p - 1]) * a[p];
	cout << rez;
}