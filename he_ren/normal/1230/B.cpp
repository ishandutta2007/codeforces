#include<cstdio>
const int MAXN = 2e5 + 5;

char s[MAXN];

int main(void)
{
	int n,k;
	scanf("%d%d%s",&n,&k,s+1);
	
	if(n==1 && k==1) s[1]='0', --k;
	for(int i=1; i<=n; ++i)
	{
		if(!k) break;
		
		char c;
		if(i==1) c='1';
		else c='0';
		
		if(s[i]==c) continue;
		else s[i]=c, --k;
	}
	
	printf("%s",s+1);
	return 0;
}