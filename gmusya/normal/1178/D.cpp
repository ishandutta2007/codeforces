#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n, m;
vector <vector <int>> arr;
int k = 0;

bool prost(int k) {
	bool tf = true;
	int z = sqrt(k);
	for (int i = 2; i <= z; i++) if (k % i == 0) tf = false;
	return tf;
}

int main() {
	cin >> n;
	int z = 3 * n / 2;
	for (int i = n; i <= z; i++) if (prost(i)) {
		cout << i << endl;
		for (int j = 1; j < n; j++) cout << j << " " << j + 1 << endl;
		cout << n << " " << 1 << endl;
		for (int j = 0; j < i - n; j++) cout << j + 1 << " " << j + 1 + n / 2 << endl;
		break;
	}
	return 0;
}