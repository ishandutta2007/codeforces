#include <bits/stdc++.h>
using namespace std;

const int mod = 2;

long long power(long long a, long long b){
	if (!b) return 1;
	long long t = power(a, b >> 1);
	return b & 1 ? t * t % mod * a % mod : t * t % mod;
}

int a[100010];

int main(){
	int b, k;
	scanf("%d%d", &b, &k);
	b %= 2;
	long long ans = 0;
	for (int i = 0; i < k; i++){
		scanf("%d", &a[i]);
		ans = (ans + a[i] * power(b, k - i - 1) % mod) % mod;
	}
	printf(ans ? "odd\n" : "even\n");
	return 0;
}