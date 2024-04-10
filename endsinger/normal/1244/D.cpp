#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
vector<int>e[N],v,a,ans,k;
long long c[N][3],d[N],s[N],out[N];
long long ansv=1e18;
main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int j=0;j<3;j++)
		for(int i=1;i<=n;i++)
			cin>>c[i][j];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		d[u]++,d[v]++;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		s[d[i]]++;
		if(d[i]==1)
			v.push_back(i);
	}
	for(int i=0;i<=n;i++)
		e[i].push_back(0),e[i].push_back(0);
	if(s[1]!=2||s[2]!=n-2)
	{
		cout<<-1<<endl;
		return 0;
	}
	int x=v[0],y=0;
	for(int i=1;i<=n;i++)
	{
		a.push_back(x);
		int ne=(e[x][0]==y?e[x][1]:e[x][0]);
		y=x;
		x=ne;
	}
	if(y!=v[1])
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==j)
				continue;
			k.clear();
			long long v=c[a[0]][i]+c[a[1]][j];
			k.push_back(i);
			k.push_back(j);
			for(int z=2;z<n;z++)
			{
				k.push_back(3-k[z-1]-k[z-2]);
				v+=c[a[z]][k[z]];
			}
			if(v<ansv||(v==ansv&&k<ans))
			{
				ansv=v;
				ans=k;
			}
		}
	}
	cout<<ansv<<endl;
	for(int i=0;i<n;i++)
		out[a[i]]=ans[i]+1;
	for(int i=1;i<=n;i++)
		cout<<out[i]<<' '; 
	return 0;
}