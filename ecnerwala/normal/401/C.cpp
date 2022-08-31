#include<iostream>

using namespace std;

bool isGood(int n, int m) {
	return m >= n - 1 && n >= (m + 1) / 2 - 1;
}

int main() {
	int n, m; cin >> n >> m;
	if(isGood(n, m)) {
		if(m == n - 1) {
			for(int i = 0; i < m; i++) cout << '0' << '1';
			cout << '0';
		} else {
			while(n) {
				if(m > n) {
					cout << '1';
					m--;
				}
				cout << '1' << '0';
				m--, n--;
			}
			for(; m; m--) cout << '1';
		}
		cout << '\n';
	} else {
		cout << -1 << '\n';
	}
	return 0;
}