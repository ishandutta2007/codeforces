#include<iostream>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<queue>
#include<algorithm>
#define N 150
#define Bt bitset<N>
#define ll long long
#define inf 100000000000000ll
using namespace std;
struct road{
	int x,y,w;
	bool operator <(const road a)const{return w<a.w;}
}rd[N];
int n;
struct matrix{
	Bt num[N];
	Bt& operator [](int a){return num[a];}
	matrix operator *(matrix a)
	{
		matrix b;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			if(num[i][j]) b[i]|=a[j];
		return b;
	}
}a;
Bt operator *(Bt a,matrix b)
{
	Bt c;
	for(int i=0;i<n;i++) c[i]=(a&b[i]).any();
	return c;
}
void ksm(matrix a,int b,Bt &r)
{
	for(;b;b>>=1)
	{
		if(b&1) r=r*a;
		a=a*a;
	}
}
Bt r;
ll dis[N],ans=inf;
queue<int>q;
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		--u,--v;
		rd[i]=(road){u,v,w};
	}
	sort(rd+1,rd+m+1);
	r[0]=1;
	int t=0;
	for(int i=1;i<=m;i++)
	{
		if(rd[i].w>=ans) break;
		int k=rd[i].w-t;
		ksm(a,k,r);
		a[rd[i].y][rd[i].x]=1;
		t=rd[i].w;
		for(int j=0;j<n;j++)
		if(r[j]) q.push(j),dis[j]=0;
		else dis[j]=inf;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int v=0;v<n;v++)
			if(a[v][u])
			{
				if(dis[v]>dis[u]+1)
				dis[v]=dis[u]+1,q.push(v);
			}
		}
		ans=min(ans,t+dis[n-1]);
	}
	if(ans>=inf) puts("Impossible");
	else printf("%lld",ans);
	return 0;
}