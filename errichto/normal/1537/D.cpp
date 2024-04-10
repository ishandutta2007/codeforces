#include <bits/stdc++.h>
using namespace std;

bool first_wins(int n) {
	if(n != 1 && __builtin_popcount(n) == 1) {
		if(__lg(n) % 2 == 1) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		if(n % 2 == 0) {
			return true;
		}
		else {
			return false;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		puts(first_wins(n) ? "Alice" : "Bob");
	}
	// vector<bool> win(301);
	// for(int n = 1; n < (int) win.size(); ++n) {
		// for(int d = 1; d <= n; ++d) {
			// if(n % d == 0 && d != 1 && d != n && !win[n-d]) {
				// win[n] = true;
			// }
		// }
		// cerr << n << ": " << win[n] << endl;
	// }
}