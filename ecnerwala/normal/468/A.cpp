#include<bits/stdc++.h>
using namespace std;

int main() {
	int N; cin >> N;
	if(N < 4) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	if(N % 2 == 0) {
		cout << "4 * 3 = 12\n";
		cout << "12 * 2 = 24\n";
		cout << "24 * 1 = 24\n";
		for(int i = 5; i < N; i += 2) {
			cout << i + 1 << " - " << i << " = " << 1 << '\n';
			cout << "24 * 1 = 24\n";
		}
	} else {
		cout << "5 - 2 = 3\n";
		cout << "3 + 3 = 6\n";
		cout << "6 * 4 = 24\n";
		cout << "24 * 1 = 24\n";
		for(int i = 6; i < N; i += 2) {
			cout << i + 1 << " - " << i << " = " << 1 << '\n';
			cout << "24 * 1 = 24\n";
		}
	}
	return 0;
}