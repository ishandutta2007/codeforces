#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstring>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define maxm 10011
#define maxn 511
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10+c-48,c=getchar();
	return t*f;
}
int n,k,a[200001],qz[200001],hz[200001],mx=-2e9;
int main()
{
	n=read();k=read();
	For(i,1,n)	a[i]=read();
	qz[0]=2e9;
	For(i,1,n)	qz[i]=min(qz[i-1],a[i]),mx=max(mx,a[i]);
	if(k>=3)	return printf("%d\n",mx),0;
	hz[n+1]=2e9;
	Dow(i,1,n)	hz[i]=min(hz[i+1],a[i]);
	if(k==1){printf("%d",hz[1]);return 0;}
	int ans=-2e9;
	For(i,1,n-1)
	{
		ans=max(ans,max(qz[i],hz[i+1]));
	}
	printf("%d\n",ans);
}