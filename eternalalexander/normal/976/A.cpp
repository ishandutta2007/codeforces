#include <bits/stdc++.h>

int main() {
	char s[10005];
	int n;
	scanf("%d%s",&n,s+1);
	int cnt = 0;
	for (int i = 1; i <= n; ++ i) 
		cnt += (s[i] == '1');
	if (cnt == 0) puts("0");
	else { printf("1"); for (int i = 1; i <= n-cnt; ++ i) printf("0");  }
	return 0;
}