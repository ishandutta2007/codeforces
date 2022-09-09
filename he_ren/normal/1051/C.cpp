#include<cstdio>
const int MAXN = 1e2 + 5;
const int MAXS = 1e2 + 5;

int s[MAXN],t[MAXS];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&s[i]);
	
	for(int i=1; i<=n; ++i)
		++t[s[i]];
	
	bool cnt=0, has=0;
	for(int i=1; i<MAXS; ++i)
	{
		if(t[i]==1) cnt^=1;
		if(t[i]>2) has=1;
	}
	if(cnt && !has){ printf("NO"); return 0;}
	
	printf("YES\n");
	for(int i=1,lst=0; i<=n; ++i)
	{
		if(t[s[i]]==2) putchar('A');
		else if(t[s[i]]==1) putchar('A'+lst), lst^=1;
		else
		{
			if(cnt) putchar('B'), cnt=0;
			else putchar('A');
		}
	}
	return 0;
}