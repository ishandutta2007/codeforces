#include<cstdio>
const int MAXN = 1e6 + 5;

int act[MAXN],cnt=0;

int main(void)
{
	int h1,a1,c1,h2,a2;
	scanf("%d%d%d%d%d",&h1,&a1,&c1,&h2,&a2);
	
	while(h2>0)
	{
		if(h2<=a1)
		{
			act[++cnt]=1;
			break;
		}
		if(h1<=a2) act[++cnt]=0, h1+=c1;
		else act[++cnt]=1, h2-=a1;
		h1-=a2;
	}
	
	printf("%d\n",cnt);
	for(int i=1; i<=cnt; ++i)
	{
		if(act[i]) printf("STRIKE\n");
		else printf("HEAL\n");
	}
	return 0;
}