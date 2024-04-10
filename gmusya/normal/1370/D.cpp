#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int L = 1, R = 1e9;
	while (L != R) {
		int M = (L + R) / 2;
		bool tf = false;
		{
			// odd
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (a[i] <= M) {
					cnt += min(n - i, 2);
					i++;
					continue;
				}
			}
			if (cnt >= k) tf = true;
		}
		{
			// even
			int cnt = 1;
			for (int i = 1; i < n; i++) {
				if (a[i] <= M) {
					cnt += min(n - i, 2);
					i++;
					continue;
				}
			}
			if (cnt >= k) tf = true;
		}
		if (tf) R = M;
		else L = M + 1;
	}
	cout << L;
	return 0;
}