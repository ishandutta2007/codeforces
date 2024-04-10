#include<cstdio>

int n,i,vis[105];
char c;

int main()
{
	scanf("%d\n",&n);
	int tn=n;
	while(tn--)
	{
		c=getchar();
		if(c=='L')
		{
			i=0;
			while(vis[i])i++;
			vis[i]=1;
		}
		if(c=='R')
		{
			i=9;
			while(vis[i])i--;
			vis[i]=1;
		}
		else vis[c-'0']=0;
	}
	for(i=0;i<10;i++)
		printf("%d",vis[i]);
	putchar('\n');
	return 0;
}