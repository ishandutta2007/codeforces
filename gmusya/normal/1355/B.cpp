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
		sort(a.begin(), a.end());
		int used = 0, g = 0;
		for (int i = 0; i < n; i++) {
			if (i + 1 - used >= a[i]) {
				used += a[i];
				g++;
			}
		}
		cout << g << '\n';
	}
	return 0;
}