#include <bits/stdc++.h>
using namespace std;

long long extendedEuclidean(long long a, long long b, long long &x, long long &y){
	if(a == 0){
		x = 0; y = 1;
		return b;
	}
	long long tx, ty;
	long long g = extendedEuclidean(b%a, a, tx, ty);
	x = ty - (b/a)*tx; y = tx;
	return g;
}

inline uint32_t inverse(uint32_t n){
	long long x, y;
	assert(extendedEuclidean(n, (1LL << 32), x, y) == 1);
	x %= (1LL << 32); if(x < (1LL << 32))x += (1LL << 32);
	return x;
}

inline uint32_t ncr(uint32_t n, uint32_t r){
	uint32_t ret = 1, pw2 = 0;
	for(uint32_t i = 0; i < r; i++){
		uint32_t x = n - i;
		while(x%2 == 0){
			pw2++;
			x >>= 1;
		}
		ret *= x;
	}
	for(int i = 0; i < r; i++){
		uint32_t x = i + 1;
		while(x%2 == 0){
			pw2--;
			x >>= 1;
		}
		ret *= inverse(x);
	}
	while(pw2 > 0){
		ret <<= 1;
		pw2--;
	}
	return ret;
}

uint32_t coef[205];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	uint32_t n, p, q;
	cin >> n >> p >> q;
	p = min(p, n - 1);
	for(int r = 0; r <= p; r++){
		coef[r] = ncr(n, r);
	}
	uint32_t answer = 0;
	for(int i = 1; i <= q; i++){
		uint32_t sum = 0, prod = i;
		for(int r = 0; r <= p; r++){
			sum += prod*coef[r];
			prod *= i;
		}
		answer ^= sum;
	}
	cout << answer << '\n';

	return 0;
}