#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define M 500010
using namespace std;
int x[M],y[M];
int f[N];
int find(int x){return x==f[x]?f[x]:(f[x]=find(f[x]));}
void merge(int x,int y)
{
	f[find(x)]=find(y);
}
short int p[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,s,t;
		scanf("%d%d%d%d",&n,&m,&s,&t);
		for(int i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]);
		for(int i=1;i<=n;i++) f[i]=i,p[i]=0;
		for(int i=1;i<=m;i++)
		if(x[i]!=s && y[i]!=s) merge(x[i],y[i]);
		for(int i=1;i<=n;i++)
		if(find(i)==find(t)) p[i]++;
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=m;i++)
		if(x[i]!=t && y[i]!=t) merge(x[i],y[i]);
		for(int i=1;i<=n;i++)
		if(find(i)==find(s)) p[i]+=2;
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++)
		if((i!=s && i!=t))
		{
			if(p[i]==1) cnt1++;
			else if(p[i]==2) cnt2++;
		}
		printf("%lld\n",1ll*cnt1*cnt2);
	}
	return 0;
}