#include <bits/stdc++.h>
#define maxn 300005
int n,k; char s[maxn];

void solve() {
	int c0 = 0, c1 = 0, c2 = 0;
	scanf("%d%d%s",&n,&k,s+1);
	for (int i = 1; i <= k; ++ i) {
		int c0 = 0, c1 = 0;
		for (int j = i; j <= n; j += k) {
			 if (s[j] == '0') c0 ++;
			 if (s[j] == '1') c1 ++;
		} 
		if (c0 && c1) { puts("NO"); return; }
		else if (c0) {
			for (int j = i; j <= n; j += k) if (s[j] == '?') s[j] = '0';
		}
		else if (c1) {
		//	printf(">%d\n",i);
			for (int j = i; j <= n; j += k) if (s[j] == '?') s[j] = '1';
		}
	}// printf("%s",s+1);
	for (int i = 1; i <= k; ++ i) {
		if (s[i] == '0') c0 ++;
		if (s[i] == '1') c1++;
		if (s[i] == '?') c2++;
	} if (! ( c0 <= k/2 && c1 <= k/2 ) ) { puts("NO");return; }
	puts("YES");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}