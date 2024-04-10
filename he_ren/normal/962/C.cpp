#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

char s[15],t[15];
int sl,tl;

void gao(int x)
{
	sprintf(t+1,"%d",x*x);
	tl=strlen(t+1);
	
	int j=1;
	for(int i=1; i<=sl && j<=tl; ++i)
		if(t[j]==s[i]) ++j;
	if(j>tl) printf("%d",sl-tl), exit(0);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	sprintf(s+1,"%d",n);
	sl=strlen(s+1);
	
	int sn=sqrt(n);
	for(int i=sn; i>=1; --i) gao(i);
	printf("-1");
	return 0;
}