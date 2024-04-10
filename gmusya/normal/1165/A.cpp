#include <iostream>	
#include <vector>

using namespace std;

int preobr(char a) {
	if (a == '1') return 1;
	if (a == '0') return 0;
}

int main() {
	int n, x, y, l;
	char z;
	cin >> n >> x >> y;
	y++;
	l = 0;
	int a[200000];
	for (int i = 0; i < n; i++) {
		cin >> z;
	    a[i] = preobr(z);
	}
	for (int i = n - x; i < n; i++) {
		if (a[i] == 1 && i != n - y) {
			l++;;
		}
		if (a[i] == 0 && i == n - y) {
			l++;
		}
	}
	cout << l;
	return 0;
}