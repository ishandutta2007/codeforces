#include<iostream>

using namespace std;

typedef long long ll;

int main() {
	ll n; cin >> n;
	cout << ((n * n) / 2 + (n * n) % 2) << '\n';
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if((i + j) % 2 == 0) cout << 'C';
			else cout << '.';
		}
		cout << '\n';
	}
	return 0;
}