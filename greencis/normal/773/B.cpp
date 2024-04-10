#include <bits/stdc++.h>
using namespace std;

int a[2][5];
int b[5];
int dif[5];
int cost(int solv, int tot) {
	if (solv * 2 > tot)
		return 2;
	if (solv * 4 > tot)
		return 4;
	if (solv * 8 > tot)
		return 6;
	if (solv * 16 > tot)
		return 8;
	if (solv * 32 > tot)
		return 10;
	return 12;
}
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
			if (a[i][j] != -1)
				b[j]++;
		}
	}
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			int x;
			cin >> x;
			if (x != -1) {
				b[j]++;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		if (a[0][i] == -1 && a[1][i] != -1)
			dif[i] = a[1][i] - 250;
		else if (a[0][i] != -1 && a[1][i] == -1)
			dif[i] = 250 - a[0][i];
		else
			dif[i] = a[1][i] - a[0][i];
	}
	int m = n;
	int sum;
	while (m < 10000) {
		sum = 0;
		for (int i = 0; i < 5; i++)
			sum += dif[i] * cost(b[i], m);
		if (sum > 0)
			break;
		m++;
		for (int i = 0; i < 5; i++)
			if (dif[i] < 0 && a[0][i] != -1)
				b[i]++;
	}
	if (sum > 0)
		cout << m - n << endl;
	else
		cout << -1 << endl;
	return 0;
}