#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int n;
vector <vector <long long int>> a;
vector <long long int> b;

int main() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++) a[i].resize(n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
	b[0] = sqrt(a[0][1] * a[0][2] / a[1][2]);
	for (int i = 1; i < n; i++) b[i] = a[i][0] / b[0];
	for (int i = 0; i < n; i++) cout << b[i] << " ";
	return 0;
}