#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int min (int a, int b) {
	int k = a;
	if (k > b) k = b;
	return k;
}

int main() {
	int t;
	cin >> t;
	vector <int> a(t);
	for (int i = 0; i < t; i++) {
		int n, s, l;
		cin >> n >> s >> l;
		a[i] = n - min (s, l) + 1;
	}
	for (int i = 0; i < t; i++) cout << a[i] << endl;
		return 0;
}