#include <iostream>

using namespace std;

void gen(int sz, int offs) {
	for (int i = 0; i < sz; i += 2) {
		for (int j = i + 2; j < sz; j += 2) {
			cout << i+0 + offs << " " << j+0 + offs << "\n";
			cout << i+1 + offs << " " << j+1 + offs << "\n";
			cout << i+0 + offs << " " << j+1 + offs << "\n";
			cout << i+1 + offs << " " << j+0 + offs << "\n";
		}
	}
}

int main() {
	int n; cin >> n;
	if (n % 4 == 0) {
		cout << "YES\n";
		gen(n, 1);
		for (int i = 0; i < n; i += 2) {
			cout << i+1 << " " << i+2 << "\n";
		}
	} else if (n % 4 == 1) {
		cout << "YES\n";
		gen(n-1, 2);
		for (int i = 1; i < n; i += 2) {
			cout << 1 << " " << i+1 << "\n";
			cout << i+1 << " " << i+2 << "\n";
			cout << 1 << " " << i+2 << "\n";
		}
	} else {
		cout << "NO\n";
	}
	return 0;
}