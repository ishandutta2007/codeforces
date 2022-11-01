#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		bool tf = true;
		sort(a.begin(), a.end());
		for (int i = 0; i < n - 1; i++)
			if (a[i] + 1 == a[i + 1])
				tf = false;
		if (tf)
			cout << "1" << endl;
		else
			cout << "2" << endl;
	}
	return 0;
}