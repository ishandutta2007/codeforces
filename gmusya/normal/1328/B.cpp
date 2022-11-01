#include <iostream>
#include <vector>

using namespace std;

int main () {
	long long t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		k = n * (n - 1) / 2 - k + 1;
		long long cnt = 0;
		long long posa = 0, posb = 0;
		for (long long i = 1; i <= n; i++) {
			if (cnt + (n - i) < k) {
				cnt += n - i;
				continue;
			}
			posa = i, posb = i + k - cnt;
			break;
		}
		for (long long i = 1; i < posa; i++)
			cout << 'a';
		cout << 'b';
		for (long long i = posa + 1; i < posb; i++)
			cout << 'a';
		cout << 'b';
		for (long long i = posb + 1; i <= n; i++)
			cout << 'a';
		cout << '\n';
	}
	return 0;
}