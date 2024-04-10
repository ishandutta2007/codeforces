#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	cout << k * (n * 6 - 1) << '\n';
	for(int i = 0; i < n; i++) {
		cout << (i * 6 + 1) * k << ' ' << (i * 6 + 2) * k << ' ' << (i * 6 + 3) * k << ' ' << (i * 6 + 5) * k << '\n';
	}
	return 0;
}

/*

   2 1 3 5
   8 7 9 11

   mod 3 is fine
 */