#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <ll> b(n);
	for (int i = 0; i < n; i++)
		cin >> b[i];
	vector <ll> a(n);
	a[0] = b[0];
	for (int i = 1; i < n; i++) {
		a[i] = a[i - 1];
		if (b[i] > 0) a[i] = a[i - 1] + b[i];
	}
	for (int i = 0; i < n; i++) {
		if (b[i] < 0) a[i] += b[i];
		cout << a[i] << " ";
	}
	return 0;
}