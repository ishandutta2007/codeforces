#include <bits/stdc++.h>
#define maxn 1000005

int n,l,r,q,pre[maxn][4];
char s[maxn];

int count(int l,int r,int i) { return pre[r][i] - pre[l-1][i]; }

int main() {
	scanf("%s",s+1);
	n = std::strlen(s+1);
	for (int i = 1; i <= n; ++ i) {
		for (int j = 0; j < 3; ++ j) pre[i][j] = pre[i-1][j];
		pre[i][s[i]-'x'] ++;
	}
	scanf("%d",&q);
	while (q-->0) {
		scanf("%d%d",&l,&r);
		int len = (r - l + 1);
		if (len < 3) { puts("YES"); continue; }
		int L = len / 3, R = (len + 2) / 3, flag = 0;
		for (int i = 0; i < 3; ++ i) 
			if (count(l,r,i) < L || count(l,r,i) > R) flag = 1;
		if (!flag) puts("YES");
		else puts("NO");
	}
	return 0;
}