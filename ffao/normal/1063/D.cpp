#include <bits/stdc++.h>
using namespace std;

long long n, l, r, k;

//[n-M -> 2*(n-M)]*C + [M -> 2M]*(C+1) == k

long long checkC(long long n, long long M, long long k, long long C, bool mustR = false) {
	//printf("check %lld %lld %lld %lld\n",n,M,k,C);
	k -= n*C;
	k -= M;
	if (k < 0) return -1;

	if (C == 0) {
		if (k == 0 && mustR) return -1;
		if (k > M) return -1;
		return k + n-M;
	}

	long long sweetR = k % C;
	if (sweetR > M) return -1;
	k -= sweetR * (C+1);
	if (k < 0) return -1;

	long long sweetL = (C+1) - (k % (C+1));
	if (sweetL == C+1) sweetL = 0;
	if (sweetL > n-M) return -1;
	k -= sweetL * C;
	if (k < 0) return -1;

	if (sweetR == 0 && mustR) {
	 	sweetR += C;
	 	k -= sweetR * (C+1);
	 	if (k < 0) return -1;
	}

	long long otL = (C+1) * min( (n-M-sweetL) / (C+1), k / C/(C+1)) ;
	k -= otL * C;

	long long otR = C * min( (M - sweetR) / C, k /C/(C+1)) ;
	k -= otR * (C+1);

	if (k != 0) return -1;
	return sweetL + otL + otR + sweetR;
}

void goC(long long n, long long M, long long k) {
	long long ans = -1;
	
	for (int C = 0; C <= k/n; C++) {
		ans = max(ans, checkC(n,M,k,C)); 
	}

	for (int C = 0; C <= k/n; C++) {
		ans = max(ans, checkC(n,M,k+1,C,true)); 
	}

	printf("%lld\n", ans);
}

long long checkN(long long L, long long R, long long k, long long swL, long long swR) {
	// [L+swL] * C + [R+swR] * (C+1) == k
	k -= R+swR;
	if (k < 0) return -1;

	long long C = k / (L+swL+R+swR);
	if (C * (L+swL+R+swR) == k) return swL+swR;
	return -1;
}


void goN(long long n, long long M, long long k) {
	long long ans = -1;
	for (int swL = 0; swL <= n-M; swL++) {
		for (int swR = 0; swR <= M; swR++) {
			ans = max(ans, checkN(n-M, M, k, swL, swR));
		}
	}

	for (int swL = 0; swL <= n-M; swL++) {
		for (int swR = 1; swR <= M; swR++) {
			ans = max(ans, checkN(n-M, M, k+1, swL, swR));
		}
	}

	printf("%lld\n", ans);
}

int main() {
	scanf("%lld %lld %lld %lld", &n, &l, &r, &k);

	r -= l;
	if (r < 0) r += n;
	r++;

	if (k/n <= 10000000) 
	  	goC(n, r, k);
	else 
		goN(n, r, k);
}