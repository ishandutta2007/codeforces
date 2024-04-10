#include <bits/stdc++.h>

int n,k,c[100];
char s[10005];

void solve() {
	scanf("%d%d",&n,&k);
	int siz = n / k;
	scanf("%s",s + 1);
	for (int i = 0; i < 26; ++ i) c[i] = 0;
	for (int i = 1; i <= n; ++ i) c[s[i] - 'a'] ++;
	for (int i = 1; i <= k; ++ i) {
		int flag = siz;
		for (int j = 0; j < 26 && j < flag; ++ j) {
			if (c[j]) c[j] --;
			else {
				flag = j;
				break;
			}
		} printf("%c",flag + 'a');
	} puts("");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}