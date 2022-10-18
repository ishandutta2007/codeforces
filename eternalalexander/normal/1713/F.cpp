#include <bits/stdc++.h>

const int maxn = 2e6 + 222;
int n,a[maxn],b[maxn];

std::vector<int> solve(int l1,int r1,int l2,int r2) {
	// solve [l2,r2] with the information from l1 to r1;
	if (l1 > r1) { std::vector<int>v; return v; }
	while (l1 > r1 / 2) {
		int len = r1  - l1;
		int r11 = r1 / 2;
		int l11 = r11 - len;
		for (int i = 0; i <= len; ++ i) 
			a[l11 + i] = a[l1 + i];
		r1 = r11;
		l1 = l11;
	}
	if (r1 == 0) {
		std::vector<int>f(1); f[0] = a[0];
		return f;
	}
	assert(r1 - l1 == r2 - l2);
	int L = 1; while (L * 2 < r1) L <<= 1;
	int U = r1 - L + 1;
	std::vector<int>f(r2 + 1),g(U); 
	for (int i = L; i <= r1; ++ i) f[i - L] = a[i];
	
	for(int i = 1; i < U; i <<= 1)
	for(int len = i<<1,j = 0; j < U; j += len)
	for(int k = 0; k < i; ++ k)
		f[j + k + i] = f[j + k] ^ f[j + k + i];

	for (int i = r2 - U + 1; i < U; ++ i) 
		g[i] = f[i];
	
	for(int i = 1; i < U; i <<= 1)
	for(int len = i<<1,j = 0; j < U; j += len)
	for(int k = 0; k < i; ++ k)
		g[j + k + i] = g[j + k] ^ g[j + k + i];
		
	for (int i = l1; i < L; ++ i) 
		a[i] ^= g[i];
	
	std::vector<int>h = solve(l1,L - 1,l2,r2 - U);
	
	for (int i = 0; i <= r2 - U; ++ i) {
		f[i + U] = h[i] ^ f[i];
		f[i] = h[i];
	}
	return f;
}

int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; ++ i) {
		scanf("%d",&b[i]);
	} 
	int U = 1; while (U < n) U <<= 1; U --;
	for (int i = 0; i < n; ++ i) 
		a[U - i] = b[i];
	std::vector <int> answ = solve(U - n + 1,U,0,n - 1);
	std::reverse(answ.begin(),answ.end());
	for (int x:answ) printf("%d ",x);
	return 0;
}