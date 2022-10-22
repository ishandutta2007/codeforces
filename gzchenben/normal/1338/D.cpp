#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,ans,dp1[100005],dp2[100005];
vector<int> vec[100005];
void check(int &x1,int &x2,int x)
{
	if(x1<x)
	{
		x2=x1; x1=x;
	}
	else if(x2<x)
	{
		x2=x;
	}
}
void dfs(int x,int fa)
{
	int tmp=0;
	int maxn11=0,maxn12=0,maxn21=0,maxn22=0;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==fa) continue;
		dfs(vec[x][i],x);
		check(maxn11,maxn12,dp1[vec[x][i]]);
		check(maxn21,maxn22,dp2[vec[x][i]]);
	}
//	printf("--------------------------------------\n");
//	printf("x=%d,fa=%d\n",x,fa);
	dp2[x]=maxn11+max(0,(int)vec[x].size()-2);
	dp1[x]=max(dp2[x],1+maxn21);
//	printf("maxn[1][1]=%d\nmaxn[1][2]=%d\nmaxn[2][1]=%d\nmaxn[2][2]=%d\n",maxn11,maxn12,maxn21,maxn22);
//	printf("dp1=%d,dp2=%d\n",dp1[x],dp2[x]);
	ans=max(ans,max(1+maxn21+maxn22,maxn11+maxn12+max(0,(int)vec[x].size()-2)));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	dfs(1,0);
	printf("%d\n",ans);
}