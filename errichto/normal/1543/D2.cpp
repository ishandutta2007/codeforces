// x + z = y
// z = guess - hidden
// guess - (guess - hidden) = hidden
// easy in 2*N queries
// g4 - g3 + g2 - g1 + g0 - hidden
// sum_guess = 0;
// sum_guess = new_guess - sum_guess;

#include <bits/stdc++.h>
using namespace std;

int k;

int subtract(int a, int b) {
	vector<int> tmp;
	while(a || b) {
		int x = a % k;
		int y = b % k;
		tmp.push_back((x - y + k) % k);
		a /= k;
		b /= k;
	}
	reverse(tmp.begin(), tmp.end());
	int diff = 0;
	for(int x : tmp) {
		diff = k * diff + x;
	}
	return diff;
}

void test_case() {
	int n;
	scanf("%d%d", &n, &k);
	int sum_guess = 0;
	for(int hidden = 0; hidden < n; ++hidden) {
		
		int ask;
		
		if(hidden % 2 == 0) {
			ask = subtract(sum_guess, subtract(0, hidden));
		}
		else {
			ask = subtract(sum_guess, hidden);
		}
		printf("%d\n", ask);
		fflush(stdout);
		int r;
		scanf("%d", &r);
		if(r == 1) {
			return;
		}
		assert(r == 0);
		sum_guess = subtract(ask, sum_guess);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}