#include<bits/stdc++.h>
using namespace std;
char s[100010],op[40];
int p[40],cnt;
void opt(int x,int y) {
	op[++cnt]=x?'R':'L';
	p[cnt]=y;
}
int main() {
	scanf("%s",s+1);
	int n=strlen(s+1);
	opt(0,2);
	n++;
	opt(1,3);
	n+=n-3;
	int t=n-2;
	opt(0,n-1);
	opt(1,t+1);
	opt(1,2*t+3);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++) {
		printf("%c %d\n",op[i],p[i]);
	}
	return 0;
}