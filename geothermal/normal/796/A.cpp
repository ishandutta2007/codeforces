#include<iostream>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	m--;
	int p[100];
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	
	int dif = 1;
	
	while(true) {
		if (m - dif >= 0 && p[m - dif] != 0 && p[m - dif] <= k) {
			break;
		}
		if (m + dif < n && p[m + dif] != 0 && p[m + dif] <= k) {
			break;
		}
		dif++;
	}
	cout << dif * 10;
}