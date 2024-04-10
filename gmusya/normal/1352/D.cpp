#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int itA = 0, itB = n - 1;
		int sumA = 0, sumB = 0;
		int lastA = 0, lastB = 0;
		bool tf = true;
		int cnt = 1;
		while (itA <= itB) {
			if (tf) {
				lastA += a[itA];
				sumA += a[itA];
				itA++;
				if (lastA > lastB) {
					lastB = 0;
					tf = false;
					cnt += (itA <= itB);
				}
				continue;
			}
			lastB += a[itB];
			sumB += a[itB];
			itB--;
			if (lastB > lastA) {
				lastA = 0;
				tf = true;
				cnt += (itA <= itB);
			}
		}
		cout << cnt << ' ' << sumA << ' ' << sumB << '\n';
	}
	return 0;
}