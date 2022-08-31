#include<iostream>

using namespace std;

int main() {
	int T; cin >> T;
	for(int t = 0; t < T; t++) {
		int n, p; cin >> n >> p;
		int e = 2 * n + p;
		for(int d = 1; e; d++) {
			for(int i = 0; i < n && e; i++) {
				cout << (i + 1) << ' ' << ((i + d) % n) + 1 << '\n';
				e--;
			}
		}
	}
	return 0;
}