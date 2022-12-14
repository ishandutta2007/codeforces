#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
#define MN 1000
priority_queue<long long> q,Q;long long ans=-1e18,ad=0,AD=0,mx[MN*MN+5],Mx[MN*MN+5];
int n,m,a[MN+5][MN+5],k,p;
int main()
{
	n=read();m=read();k=read();p=read();
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j) a[i][j]=read();
	for(int i=1;i<=n;++i)
	{
		int tot=0;
		for(int j=1;j<=m;++j) tot+=a[i][j];
		q.push(tot);	
	}
	for(int i=1;i<=k;++i)
	{
		mx[i]=mx[i-1]+q.top();
		long long x=q.top();q.pop();q.push(x-m*p);	
	}
	for(int i=1;i<=m;++i)
	{
		int tot=0;
		for(int j=1;j<=n;++j) tot+=a[j][i];
		Q.push(tot);	
	}
	for(int i=1;i<=k;++i)
	{
		Mx[i]=Mx[i-1]+Q.top();
		long long x=Q.top();Q.pop();Q.push(x-n*p);	
	}
	for(int i=0;i<=k;++i)
		ans=max(ans,mx[i]+Mx[k-i]-1LL*i*(k-i)*p);
	printf("%lld\n",ans);
	return 0;
}