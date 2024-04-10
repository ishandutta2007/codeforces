/*input

5
10 21 10 21 10

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int pyr[n];
	int sum[n] = {};

	for (int i = 0; i < n; i++)
		cin >> pyr[i];

	sum[n - 1] = pyr[n - 1];

	for (int i = n - 2; i >= 0; i--)
		sum[i] = sum[i + 1] + pyr[i];

	int din[n] = {};
	din[n - 1] = pyr[n - 1];

	for (int i = n - 2; i >= 0; i--)
		din[i] = max(sum[i + 1] - din[i + 1] + pyr[i], din[i + 1]);

	cout << sum[0] - din[0] << " " << din[0];

	return 0;
}