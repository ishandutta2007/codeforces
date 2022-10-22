#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,b[N],a[N],vis[N],s,y[N];
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		a[i]=b[i]=vis[i]=y[i]=0;
	s=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(!vis[b[i]])
		{
			a[i]=b[i];
			vis[b[i]]=1;
			y[b[i]]=i;
			s++;
		}
	}
	int p=1;
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			while(vis[p])
				p++;
			vis[p]=1;
			a[i]=p;
			y[p]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==i)
		{
			int t=y[b[i]];
			swap(a[i],a[t]);
			swap(y[b[i]],y[i]);
		}
	}
	printf("%d\n",s);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
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