#include <bits/stdc++.h>
using namespace std;

vector<int> get_divisors(int a) {
	vector<int> divisors;
	for(int x = 1; x * x <= a; ++x) {
		if(a % x == 0) {
			divisors.push_back(x);
			if(x * x != a) {
				divisors.push_back(a / x);
			}
		}
	}
	return divisors;
}

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	if(a == b) {
		puts("0");
		return 0;
	}
	int diff = abs(a - b);
	pair<long long, int> answer = {LONG_LONG_MAX, -1};
	for(int d : get_divisors(diff)) {
		int r = a % d; // 47   d=10   7
		int k = (d - r) % d;
		long long tmp = lcm<long long>(a + k, b + k); //(long long) (a + k) * (b + k) / __gcd(a + k, b + k);
		answer = min(answer, make_pair(tmp, k));
	}
	printf("%d\n", answer.second);
}