#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1010
using namespace std;
int num[N],cnt[N];
int ans[N],att,tot;
int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		memset(cnt,0,sizeof(cnt));
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&num[i]),cnt[num[i]]++;
		tot=att=0;
		while(tot<n)
		{
			bool t=false;
			for(int i=tot;i<n;i++)
			if(num[i]==i) ++tot;
			else break;
			for(int i=tot;i<n;i++)
			if(!cnt[i])
			{
				ans[++att]=i+1;
				cnt[num[i]]--;
				num[i]=i;
				cnt[i]++;
				t=true;
				break;
			}
			if(!t)
			{
				for(int i=tot;i<n;i++)
				if(num[i]==tot)
				{
					ans[++att]=i+1;
					ans[++att]=tot+1;
					cnt[num[tot]]--;
					cnt[n]++;
					num[i]=n;
					num[tot]=tot;
				}
			}
		}
		printf("%d\n",att);
		for(int i=1;i<=att;i++) printf("%d ",ans[i]);
		puts("");
	}
	
	return 0;
}