#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,f[N],p[N],d;
vector<int>a[N];
int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
void mg(int u,int v){u=fa(u),v=fa(v);if(u!=v)f[u]=v;}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		a[i].clear();
		f[i]=i;
	}
	d=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x].push_back(i);
	}
	if(n&1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i].size()&1)
			{
				if(a[i].back()==n/2+1)
					swap(a[i].front(),a[i].back());
				if(a[i].back()==n/2+1)
				{
					puts("NO");
					return;
				}
				p[n/2+1]=a[i].back();
				a[i].pop_back();
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].size()&1)
		{
			puts("NO");
			return;
		}
		while(a[i].size())
		{
			d++;
			p[d]=a[i].back();
			a[i].pop_back();
			p[n-d+1]=a[i].back();
			a[i].pop_back();
		}
	}
	for(int i=1;i<=n;i++)
		mg(i,p[i]);
	for(int i=1;i<=n;i++)
	{
		if(fa(i)!=fa(n-i+1))
		{
			swap(p[i],p[n-i+1]);
			mg(i,n-i+1);
		}
	}
	for(int i=1;i<n/2;i++)
	{
		if(fa(i)!=fa(i+1))
		{
			swap(p[i],p[n-i+1]);
			swap(p[i],p[i+1]);
			swap(p[n-i+1],p[n-i]);
			mg(i,i+1);
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%d ",p[i]);
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