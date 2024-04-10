#include <iostream>
#include <vector>

using namespace std;

int n, a1, a2, k1, k2;

int min(int a, int b) {
	int k = a;
	if (k > b) k = b;
	return k;
}

int max(int a, int b) {
	int k = a;
	if (k < b) k = b;
	return k;
}

void swap() {
	int sw = a1;
	a1 = a2;
	a2 = sw;
	sw = k1;
	k1 = k2;
	k2 = sw;
}

int main() {
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	int ansmin = 0, ansmax = 0;
	ansmin = max(0, n - ((k1 - 1) * a1 + (k2 - 1) * a2));
	if (k1 < k2) swap();
	ansmax += min(a2, n / k2);
	n -= ansmax * k2;
	ansmax += min(a1, n / k1);
	cout << ansmin << " " << ansmax;
	return 0;
}