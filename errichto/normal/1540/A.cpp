#include <bits/stdc++.h>
using namespace std;

void test_case() {
	int n;
	scanf("%d", &n);
	vector<int> d(n);
	for(int& x : d) {
		scanf("%d", &x);
	}
	long long answer = *max_element(d.begin(), d.end());
	// for(int i = 0; i < n; ++i) {
		// for(int j = i + 1; j < n; ++j) {
			// answer -= abs(d[i] - d[j]);
		// }
	// }
	sort(d.begin(), d.end());
	for(int i = 0; i < n; ++i) {
		answer -= (long long) d[i] * (i - (n - 1 - i));
	}
	printf("%lld\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}