#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if(sum % 2 == 1) {
		puts("0");
		return 0;
	}
	sum /= 2; // target
	vector<bool> possible(sum + 1);
	possible[0] = 1;
	// possible[s] true iff we can get sum s
	for(int x : a) {
		for(int i = sum - x; i >= 0; --i) {
			if(possible[i]) {
				possible[i+x] = true;
			}
		}
	}
	if(possible[sum]) {
		// need to remove something
		while(true) {
			for(int i = 0; i < n; i++) {
				if(a[i] % 2 == 1) { // odd
					cout << "1\n";
					cout << i + 1 << "\n";
					return 0;
				}
			}
			// all even
			for(int i = 0; i < n; i++) {
				a[i] /= 2;
			}
		}
	}
	else {
		puts("0");
	}
}

// O(N * SUM) = O(N * N * MAX)