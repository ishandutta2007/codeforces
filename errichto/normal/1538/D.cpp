// this is a warm-up problem,
// we will switch to harder ones later

// 36 -> 18 -> 9 -> 3 -> 1

// 36 = 2*2*3*3


// 48 -> 24 -> 12 -> 6 -> 3 -> 1

// 48 = product of five primes 2*2*2*2*3

// 9 steps at most, 2 at least


// O(T*sqrt(A)) -> O(T * sqrt(A) / log(A))

#include <bits/stdc++.h>
using namespace std;

constexpr int L = sqrt(1e9) + 5;
bool is_prime[L];
vector<int> primes;

int count_primes(int a) {
	int count = 0;
	for(int p : primes) {
		if(p * p > a) {
			break;
		}
		while(a % p == 0) {
			a /= p;
			count++;
		}
	}
	if(a != 1) {
		count++;
	}
	return count;
}

bool test_case() {
	int a, b, k;
	scanf("%d%d%d", &a, &b, &k);
	if(k == 1) {
		return a != b && (a % b == 0 || b % a == 0);
	}
	return k <= count_primes(a) + count_primes(b);
}

int main() {
	
	// prime sieve
	for(int p = 2; p < L; ++p) {
		is_prime[p] = true;
	}
	for(int p = 2; p < L; ++p) {
		if(is_prime[p]) {
			primes.push_back(p);
			for(int x = p * p; x < L; x += p) {
				is_prime[x] = false;
			}
		}
	}
	
	int T;
	scanf("%d", &T);
	while(T--) {
		puts(test_case() ? "YES" : "NO");
	}
}