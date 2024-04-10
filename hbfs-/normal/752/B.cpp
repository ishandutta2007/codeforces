#include <iostream>
#include <cstdio>
#include <cstring>

#define N 100050

using namespace std;
char s[N],t[N];
int n,F[N],tot;

int main()
{
	scanf("%s",s+1);
	scanf("%s",t+1);
	n = strlen(s+1); bool flag = true;
	for (int i=1;i<=n;i++) {
		int c1 = s[i] - 'a' + 1 , c2 = t[i] - 'a' + 1;
		if (c1 == c2) {
			if (!F[c1]) F[c1] = c1;
			if (F[c1] != c1) flag = false;  
			continue;
		}
		if (F[c1] == c2 && F[c2] == c1) continue;
		if (!F[c1] && !F[c2]) tot++;
		if (!F[c1]) {
			F[c1] = c2;
		} else {
			if (F[c1] != c2) flag = false;
		}
		
		if (!F[c2]) {
			F[c2] = c1;
		} else {
			if (F[c2] != c1) flag = false;
		}
	}
	
	if (!flag) puts("-1"); else {
		printf("%d\n",tot);
		for (int i=1;i<=26;i++) if (F[i] && F[i] != i) {
			printf("%c %c\n",i+'a'-1,F[i]+'a'-1);
			F[ F[i] ] = 0;
		}
	}
	return 0;
}