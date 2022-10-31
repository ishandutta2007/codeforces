#include<cstdio>
void print(int x,int ans)
{
	if(!x) return;
	if(x==1)
	{
		printf("%d\n",ans);
		return;
	}
	if(x==2)
	{
		printf("%d %d\n",ans,ans<<1);
		return;
	}
	if(x==3)
	{
		printf("%d %d %d\n",ans,ans,ans*3);
		return;
	}
	int cnt=0;
	for(int i=1;i<=x;i+=2)
	{
		printf("%d ",ans);
		++cnt;
	}
	print(x-cnt,ans<<1);
}
int main()
{
	int n;
	scanf("%d",&n);
	print(n,1);
	return 0;
}