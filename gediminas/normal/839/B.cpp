/*input
1 4
2 2 1 2
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, k;
	cin >> k >> n;
	int mas[n];

	for (int i = 0; i < n; i++)
		cin >> mas[i];

	int ketv = k;

	for (int i = 0; i < n; i++) {
		int galim = min(mas[i] / 4, ketv);
		mas[i] -= galim * 4;
		ketv -= galim;
	}

	for (int i = 0; i < n; i++) {
		int galim = min(mas[i] / 3, ketv);
		mas[i] -= galim * 3;
		ketv -= galim;
	}

	int dviem = 2 * k + ketv;

	for (int i = 0; i < n; i++) {
		int galim = min(mas[i] / 2, dviem);
		mas[i] -= galim * 2;
		dviem -= galim;
	}

	int vienam = ketv + dviem;

	for (int i = 0; i < n; i++)
		vienam -= mas[i];


	if (vienam >= 0)
		cout << "YES";
	else
		cout << "NO";


	return 0;
}