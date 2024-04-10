// every previous number is a submask of next number

// 000010
// 000011
// 001111
// 101111

// 101111
// 100110 <- submask of previous mask

// x is submask of y <==> y is supermask of x

// lexicographically minimal
// first, minimize the first element


// x: a b c d e f
// y: 0 ! ?
   // a ! ? 
   
// a = 11100010
// b'= 11111011
// b = 00111001
   
// y = 110...1.
// y = 11000010   

#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	vector<int> y(n);
	// y[0] = 0;
	for(int i = 1; i < n; ++i) { // O(N*log(value))
		int a = x[i-1] ^ y[i-1];
		// x[i] ^ y[i] must be supermask of a
		
		y[i] = a & ~x[i];
		
		// for(int bit = 0; bit < 30; ++bit) {
			// if(a & (1 << bit)) {
				// if((x[i] & (1 << bit)) == 0) {
					// y[i] ^= 1 << bit;
				// }
			// }
		// }
	}
	for(int i = 0; i < n; ++i) {
		cout << y[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int i = 0; i < T; i++) {
		test_case();
	}
}