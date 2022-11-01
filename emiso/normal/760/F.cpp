#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int n, ways[5050][5050], last[27], fat[5050], ifat[5050];
char s[5050];

int expo(int b, int e) {
	if(!e) return 1;
	if(e & 1) return 1LL * b * expo(1LL * b * b % MOD, e >> 1) % MOD;
	return expo(1LL * b * b % MOD, e >> 1);
}

int invmod(int x) { return expo(x, MOD - 2); }

void prep() {
	fat[0] = 1;
	for(int i = 1; i < 5050; i++)
		fat[i] = 1LL * fat[i-1] * i % MOD;
	
	ifat[5050-1] = invmod(fat[5050-1]);
	for(int i = 5050-1; i > 0; i--)
		ifat[i-1] = 1LL * ifat[i] * i % MOD;
	
	assert(ifat[0] == 1);
}

long long nCr(int n, int k) {
	return 1LL * fat[n] * ifat[k] % MOD * ifat[n-k] % MOD;
}

int main() {
	scanf("%d %s", &n, s + 1); 
	
	prep();
	s[0] = char('a' + 26);
	last[26] = n+1;
	ways[n+1][0] = 1;
	
	for(int i = n; i >= 0; i--) {
		for(int c = 0; c < 27; c++) {
			if(c == (s[i] - 'a') || (last[c] == 0)) continue;
			for(int j = 0; j < (n - i + 1); j++) {
				ways[i][j+1] += ways[last[c]][j];
				if(ways[i][j+1] >= MOD) ways[i][j+1] -= MOD;
			}
		}
		last[s[i]-'a'] = i;
	}
		
	long long ans = 0;
	for(int i = 2; i <= n + 1; i++) {
		ans = (ans + nCr(n-1, i-2) * ways[0][i]) % MOD;
	}
	
	printf("%lld\n", ans);
	return 0;
}