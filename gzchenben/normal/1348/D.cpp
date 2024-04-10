#include<cstdio>
#include<cstring>
using namespace std;
int n,t,ans[1005];
int main()
{
	ans[0]=1;
	scanf("%d",&t);
	for(int x=1;x<=t;x++)
	{
		scanf("%d",&n);
		int tmp=1,num=1,now=0;
		while(tmp<n)
		{
			now++;
			num*=2;
			if(tmp+num>=n)
			{
				ans[now]=n-tmp;
				break;
			}
			ans[now]=num;
			tmp+=num;
		}
		if(now>=2)
		{
			if(ans[now]<ans[now-1])
			{
				int tmp_=(ans[now-1]-ans[now]+1)/2;
				ans[now]+=tmp_;
				ans[now-1]-=tmp_;
			}
		}
		printf("%d\n",now);
		for(int i=1;i<=now;i++)
		{
			printf("%d ",ans[i]-ans[i-1]);
		}
		printf("\n");
	}
}