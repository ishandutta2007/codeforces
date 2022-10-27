#include <bits/stdc++.h>
using namespace std;

const int N = 20005;

int n, sq, sz;
uint32_t A, B, C, D;
int prime[N], chk[N];
uint32_t large[N][4];
uint32_t small[N][4];

inline uint32_t sum0(int m){
	return m;
}

inline uint32_t sum1(int m){
	uint32_t x = m;
	uint32_t y = m + 1;
	if(x&1){
		y >>= 1;
	}else{
		x >>= 1;
	}
	return x*y;
}

inline uint32_t sum2(int m){
	uint32_t x = m;
	uint32_t y = m + 1;
	uint32_t z = 2*m + 1;
	if(x&1){
		y >>= 1;
	}else{
		x >>= 1;
	}
	if(x%3 == 0){
		x /= 3;
	}else if(y%3 == 0){
		y /= 3;
	}else{
		z /= 3;
	}
	return x*y*z;
}

inline uint32_t sum3(int m){
	return sum1(m)*sum1(m);
}

inline uint32_t get(int m, int k){
	if(m <= sq)return small[m][k];
	return large[n/m][k];
}

void init(){
	sq = 0, sz = 0;
	while((sq + 1)*(sq + 1) <= n)sq++;
	memset(chk, 0, sizeof(chk));
	for(int i = 2; i <= sq; i++){
		if(chk[i])continue;
		prime[sz] = i; ++sz;
		for(int j = i + i; j <= sq; j += i){
			chk[j] = 1;
		}
	}
	for(int i = 1; i <= sq; i++){
		small[i][0] = sum0(i) - 1;
		small[i][1] = sum1(i) - 1;
		small[i][2] = sum2(i) - 1;
		small[i][3] = sum3(i) - 1;
	}
	for(int i = 1; i <= sq; i++){
		int r = n/i;
		large[i][0] = sum0(r) - 1;
		large[i][1] = sum1(r) - 1;
		large[i][2] = sum2(r) - 1;
		large[i][3] = sum3(r) - 1;
	}
	for(int iter = 0; iter < sz; iter++){
		int p = prime[iter];
		for(int i = 1; i <= sq; i++){
			int r = n/i;
			if(p*p > r)break;
			large[i][0] -= (get(r/p, 0) - get(p - 1, 0));
			large[i][1] -= (get(r/p, 1) - get(p - 1, 1))*p;
			large[i][2] -= (get(r/p, 2) - get(p - 1, 2))*p*p;
			large[i][3] -= (get(r/p, 3) - get(p - 1, 3))*p*p*p;
		}
		for(int i = sq; i >= 1; i--){
			if(p*p > i)break;
			small[i][0] -= (get(i/p, 0) - get(p - 1, 0));
			small[i][1] -= (get(i/p, 1) - get(p - 1, 1))*p;
			small[i][2] -= (get(i/p, 2) - get(p - 1, 2))*p*p;
			small[i][3] -= (get(i/p, 3) - get(p - 1, 3))*p*p*p;
		}
	}
	large[sq + 1][0] = small[sq][0];
	large[sq + 1][1] = small[sq][1];
	large[sq + 1][2] = small[sq][2];
	large[sq + 1][3] = small[sq][3];
}

inline uint32_t f(uint32_t x){
	return ((A*x + B)*x + C)*x + D;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> A >> B >> C >> D;
	
	init();
	uint32_t answer = 0;
	for(int i = 2; i <= sq; i++){
		if(!chk[i]){
			uint32_t val = 0;
			for(int y = n/i; y > 0; y /= i){
				val += y;
			}
			val *= f(i); answer += val;
		}
	}
	for(int i = 1; i <= sq; i++){
		answer += (large[i][0] - large[i + 1][0])*i*D;
		answer += (large[i][1] - large[i + 1][1])*i*C;
		answer += (large[i][2] - large[i + 1][2])*i*B;
		answer += (large[i][3] - large[i + 1][3])*i*A;
	}
	cout << answer << '\n';

	return 0;
}