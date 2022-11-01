#include <iostream>
#include <vector>

using namespace std;
int n;
vector <char> a;

int main() {
	cin >> n;
	a.resize(n);
	int z = -1;
	int x = -1;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (a[i] == 'z') z++;
		if (a[i] == 'n') x++;
	}
	for (int i = 0; i <= x; i++) cout << "1 ";
	for (int i = 0; i <= z; i++) cout << "0 ";
	return 0;
}