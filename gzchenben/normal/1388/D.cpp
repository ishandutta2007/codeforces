#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,a[200005],b[200005];
vector<int> vec[200005],ans1,ans2;
long long ans,f[200005];
void dfs(int x)
{
	f[x]=a[x];
	for(int i=0;i<vec[x].size();i++)
	{
		dfs(vec[x][i]);
		f[x]+=max(f[vec[x][i]],0ll);
	}
	ans+=f[x];
	if(f[x]<0) ans2.push_back(x);
	else ans1.push_back(x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]!=-1) vec[b[i]].push_back(i);
	}
	for(int i=1;i<=n;i++) if(b[i]==-1) dfs(i);
	printf("%lld\n",ans);
	for(int i=0;i<ans1.size();i++) printf("%d ",ans1[i]);
	for(int i=ans2.size()-1;i>=0;i--) printf("%d ",ans2[i]);
	printf("\n");
}