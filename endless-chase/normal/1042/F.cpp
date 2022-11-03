#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,k,x,y,rt,ans;
vector<int> g[1111111];
int dfs(int i,int fa,int dep)
{
	if (g[i].size()==1) return dep;
	vector<int> v;v.clear();
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		v.push_back(dfs(to,i,dep+1));
	}
	sort(v.begin(),v.end());
	int oo=v.size(),pos=-1;
	for (int i=oo-1;i>=1;i--)
	{
		if (v[i]+v[i-1]-2*dep>k) ans++;
		else 
		{
			pos=i;
			break;
		}
	}
	if (!~pos) pos=0;
	return v[pos];
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);  
	}
	for (int i=1;i<=n;i++)
	{
		if (g[i].size()>1) 
		{
			rt=i;
			break;
		}
	}
	dfs(rt,0,0);
	printf("%d\n",ans+1);
	return 0;
}