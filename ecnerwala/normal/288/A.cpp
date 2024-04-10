#include<iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if(n < k) {
		cout << -1;
	} else if(k == 1) {
		if(n == 1) cout << 'a';
		else cout << -1;
	} else {
		for(int i = 0; i < n - (k - 2); i++) cout << (char)('a' + i % 2);
		for(int i = 2; i < k; i++) cout << (char)('a' + i);
	}
	cout << '\n';
	return 0;
}