#include<bits/stdc++.h>
using namespace std;
int sum[300005];
char s[300005];
int n,m;
vector<int> G[600005];
map<int,int> M;
void Solve()
{
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	int id=0;
	for(int i=1;i<=n;++i)
	{
		if(i&1)	sum[i]=sum[i-1]+(s[i]=='+'?1:-1);
		else	sum[i]=sum[i-1]+(s[i]=='+'?-1:1);
		if(M[sum[i]])	G[M[sum[i]]].push_back(i);
		else	M[sum[i]]=++id,G[M[sum[i]]].push_back(i);
	}
	while(m-->0)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		if((r-l+1)&1)
		{
			puts("1");
			int deg=sum[r]-sum[l-1];
			deg=(deg>0?deg+1:deg-1)/2;
			deg+=sum[l-1];
			deg=M[deg];
			int pos=*lower_bound(G[deg].begin(),G[deg].end(),l);
			printf("%d\n",pos);
		}
		else
		{
			if(sum[r]-sum[l-1])
			{
				puts("2");
				printf("%d ",l);
				++l;
				int deg=sum[r]-sum[l-1];
				deg=(deg>0?deg+1:deg-1)/2;
				deg+=sum[l-1];
				deg=M[deg];
				int pos=*lower_bound(G[deg].begin(),G[deg].end(),l);
				printf("%d\n",pos);
			}
			else
			{
				puts("0");
			}
		}
	}
	for(int i=1;i<=id;++i)	G[i].clear();
	M.clear();
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}