#include <bits/stdc++.h>

 
long long s00, s01, s10, s11;

void solve() {
	scanf("%lld %lld %lld %lld", &s00, &s01, &s10, &s11);

	long long zeros, ones;
	if (s00 == 0) {
		if (s01 || s10) zeros = 1;
		else zeros = 0;
	}
	else {
		for (zeros = 1; ; zeros++) {
			long long c = (zeros * (zeros-1)) / 2;
			if (c > s00) {
				printf("Impossible\n");
				return;
			}
			else if (c == s00) break;
		}
	}

	if (s11 == 0) {
		if (s01 || s10) ones = 1;
		else ones = 0;
	}
	else {
		for (ones = 1; ; ones++) {
			long long c = (ones * (ones-1)) / 2;
			if (c > s11) {
				printf("Impossible\n");
				return;
			}
			else if (c == s11) break;
		}
	}

	if (zeros == 0 && ones == 0) zeros++;
	
	long long n = zeros + ones;
	long long tot = (n * (n-1)) / 2;
	if (tot != s00 + s01 + s10 + s11) {
		printf("Impossible\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		if (ones <= s01) {
			printf("0");
			s01 -= ones;
		}
		else {
			printf("1");
			ones--;
		}
	}
	printf("\n");
}


int main() {
    solve();
}