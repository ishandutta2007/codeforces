#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <int> d;
		for (int i = 1; i * i <= n; i++) 
			if (n % i == 0) d.push_back(i);
		for (int i = d.size() - 1; i >= 0; i--)
			if (d[i] * d[i] != n)
				d.push_back(n / d[i]);
		int ma;
		for (int i = d.size() - 1; i >= 0; i--)
			if (d[i] <= k) {
				ma = d[i];
				break;
			}
		cout << n / ma << '\n';
	}
	return 0;
}