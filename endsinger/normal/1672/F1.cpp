#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],c[N],p[N];
vector<int>f[N];
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		c[i]=0;
		f[i].clear();
		p[i]=i;
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		c[a[i]]++;
		f[c[a[i]]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		auto &g=f[i];
		if(g.size()>1)
		{
			sort(g.begin(),g.end(),[&](int x,int y){return c[a[x]]==c[a[y]]?a[x]<a[y]:c[a[x]]>c[a[y]];});
			for(int j=0;j+1<g.size();j++)
				p[g[j+1]]=g[j];
			p[g[0]]=g[g.size()-1];
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[p[i]]);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}