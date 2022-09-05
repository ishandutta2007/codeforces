#include <bits/stdc++.h>
using namespace std;
 
void test_case() {
	int n;
	scanf("%d", &n);
	int answer = 0;
	while(n != 0) {
		int digit = n % 10;
		answer = max(answer, digit);
		n /= 10;
	}
	printf("%d\n", answer);
}
 
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}