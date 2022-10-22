#include<bits/stdc++.h>
using namespace std;
int n,a[600005],sum[600005];
bool vis[600005];
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		int m;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]),sum[i]=0;
		for(int i=1;i<=n;++i)	++sum[(a[i]-i+n-1)%n+1];
		vector<int> Ans;
		for(int i=n;i;--i)
		{
			if((n-m)/2<=sum[i])
			{
				int st=n;
				for(int j=1;j<=n;++j)	vis[j]=false;
				for(int j=1;j<=n;++j)
				{
					if(!vis[j])
					{
						int pos=j;
						do
						{
							vis[pos]=true;
							pos=(a[pos]-i+n-1)%n+1;
						}while(!vis[pos]);
						--st;
					}
				}
				if(st<=m)	Ans.push_back(n-i);
			}
		}
		printf("%d",int(Ans.size()));
		for(auto st:Ans)	printf(" %d",st);
		puts("");
	}
	return 0;
}