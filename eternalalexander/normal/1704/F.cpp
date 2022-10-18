#include <bits/stdc++.h>

const int maxn = 1e6 + 222;
int SG[1005],n;
char s[maxn];

int sg(int x) {
	if (x > 150) return SG[x%34+34+34];
	else return SG[x];
}

void solve() {
	scanf("%d",&n);
	scanf("%s",s+1);
	int last = 0, res = 0, cR = 0, cB = 0;
	for (int i = 1; i <= n; ++ i) {
		if (i > 1) {
			if (s[i] != s[i-1]) last ++;
			else if (last > 0) { res ^= sg(last + 1); last = 0; }
		}
		if (s[i] == 'R') cR ++;
		else cB ++;
	}
	if (last > 0) {  res ^= sg(last + 1); }
//	printf("res = %d\n",res);
	if (res) {
		if (cR >= cB) puts("Alice");
		else puts("Bob");
	} else {
		if (cR > cB) puts("Alice");
		else puts("Bob");
	}
}
			

int main() {
	SG[0] = SG[1] = 0;
	for (int i = 2; i <= 200; ++ i) {
		int f[200] = {0};
		for (int j = 1; j < i; ++ j) f[SG[j-1] ^ SG[i-j-1]] = 1;
		while (f[SG[i]]) SG[i] ++;
	}
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}