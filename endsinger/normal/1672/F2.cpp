#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,k,z,a[N],b[N],c[N],d[N],f[N],q[N],bg,ed;
vector<int>e[N];
deque<int>p;
void add(int u,int v)
{
	e[u].push_back(v);
	d[v]++;
}
void init()
{
	for(int i=0;i<=n+1;i++)
		a[i]=b[i]=c[i]=d[i]=0,f[i]=1e9;
	m=k=z=bg=ed=0;
	for(int i=0;i<=n;i++)
		e[i].clear();
	while(p.size())
		p.pop_back();
}
void sol()
{
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		c[a[i]]++;
		m=max(m,c[a[i]]);
	}
	for(int i=1;i<=n;i++)
		if(c[i]==m)
			z=i,k++;
	for(int i=1;i<=n;i++)
		if(a[i]!=z&&b[i]!=z)
			add(a[i],b[i]);
	for(int i=1;i<=n;i++)
		if(!d[i])
			q[ed++]=i;
	while(bg<ed)
	{
		int u=q[bg++];
		for(auto v:e[u])
			if(!--d[v])
				q[ed++]=v;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i])
		{
			puts("WA");
			return;
		}
	}
	for(int i=1;i<=n;i++)
		if(a[i]==z||b[i]==z)
			add(a[i],b[i]==z?n+1:b[i]);
	f[z]=0;
	p.push_back(z);
	while(p.size())
	{
		int u=p.front();
		p.pop_front();
		for(auto v:e[u])
		{
			if(c[v]!=m)
			{
				if(f[v]>f[u])
				{
					f[v]=f[u];
					p.push_front(v);
				}
			}
			else
			{
				if(f[v]>f[u]+1)
				{
					f[v]=f[u]+1;
					p.push_back(v);
				}
			}
		}
	}
	puts(f[n+1]==k-1?"AC":"WA");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}