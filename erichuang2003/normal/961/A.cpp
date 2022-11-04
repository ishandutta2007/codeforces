#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
int cnt[1010];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		cnt[x]++;
		bool flag=true;
		for(int j=1;j<=n;j++)
			if(cnt[j]==0)
			{
				flag=false;
				break;
			}
		if(flag)
		{
			for(int j=1;j<=n;j++)
				cnt[j]--;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}