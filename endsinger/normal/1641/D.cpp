#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
const int N=100005,B=20000;
int n,m,r=INT_MAX,t;
vector<int>a[N];
unordered_map<int,int>mp;
bitset<B>b[N],c;
int id(int x)
{
	if(mp.find(x)!=mp.end())
		return mp[x];
	t++;
	b[t]=0;
	return mp[x]=t;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		a[i].resize(m+1);
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
		scanf("%d",&a[i][0]);
	}
	sort(a,a+n);
	for(int x=0;x<=n;x+=B)
	{
		int y=min(n-1,x+B-1);
		mp.clear();
		t=0;
		for(int i=x;i<=y;i++)
			for(int j=1;j<=m;j++)
				b[id(a[i][j])][i-x]=1;
		for(int i=0;i<n;i++)
		{
			int p=0,f=1;
			c.set();
			if(a[0][0]+a[i][0]>=r)
				break;
			for(int j=1;j<=m&&f;j++)
			{
				if(mp.find(a[i][j])!=mp.end())
					c&=~b[id(a[i][j])];
				p=c._Find_first();
				if(y-x<p)
					f=0;
			}
			if(f&&p<=y-x)
				r=min(r,a[i][0]+a[x+p][0]);
		}
	}
	printf("%d\n",r==INT_MAX?-1:r);
	return 0;
}