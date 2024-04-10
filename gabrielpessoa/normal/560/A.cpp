#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x == 1) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << "1" << endl;
}