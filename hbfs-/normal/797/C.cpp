#include <bits/stdc++.h>
#define N 1000500
using namespace std;
char s[N];
int L[N],sta[N],tp,n;
int main() {
	scanf("%s",s+1); n = strlen(s+1);
	for (int i=n;i>=1;i--) L[ s[i]-'a' ]++;
	
	for (int i=1;i<=n;i++) {
		L[ s[i]-'a' ]--;
		sta[++tp] = s[i] - 'a';
		int flag = 1;
		while (tp && flag) {
			for (int j=0;j<sta[tp];j++) if (L[j]) {flag=0;break;}
			if (flag) {
				putchar(sta[tp]+'a');
				sta[tp--] = 0;
			}
		}
	}
	
	while (tp) putchar(sta[tp]+'a'), tp--;
	putchar('\n');
	return 0;
}