#include <bits/stdc++.h>

typedef long long ll;
const int maxn = 1 << 20;
const int mod = 1e9 + 7;
const int inv2 = (mod + 1) / 2;

int n,f[maxn],lim,ans;
char s[maxn + 10];

void FWT(int *a,int lim,int flag) {
	for (int i = 1; i < lim; i <<= 1)
	for (int j = 0; j < lim; j += (i << 1))
	for (int k = 0; k < i; ++ k) {
		int a1 = a[j+k], a2 = a[j+k+i];
		a[j+k] = (a1 + a2) % mod;
		a[j+k+i] = (a1 - a2 + mod) % mod;
		if (flag == -1) { a[j+k] = (ll) a[j+k] * inv2 % mod; a[j+k+i] = (ll) a[j+k+i] * inv2 % mod; }
	}
}

int main() {
	scanf("%d%s",&n,s);
	lim = 1 << n;
	for (int i = 0; i < lim; ++ i) f[i] = s[i] - '0';
	FWT(f,lim,1);
	for (int i = 0; i < lim; ++ i) f[i] = (ll) f[i] * f[i] % mod;
	FWT(f,lim,-1);
	for (int i = 0; i < lim; ++ i) 
		ans = (ans + (ll) f[i] * (1 << (n - __builtin_popcount(i))) % mod ) % mod;
	printf("%lld",(ll)ans * 3 % mod);
	return 0;
}