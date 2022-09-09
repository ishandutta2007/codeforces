#include<cstdio>

bool vis[15];
inline bool can(int x)
{
	for(int i=0; i<=9; ++i) vis[i]=0;
	while(x)
	{
		int t=x%10;
		if(vis[t]) return 0;
		vis[t]=1;
		x/=10;
	}
	return 1;
}

int main(void)
{
	int l,r;
	scanf("%d%d",&l,&r);
	for(int i=l; i<=r; ++i)
	{
		if(can(i))
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}