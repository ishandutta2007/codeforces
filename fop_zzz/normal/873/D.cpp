#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#define eps 1e-5
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define maxn 1000000
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int n,k,t,a[200001],tot,tep;
inline void build(int l,int r)
{
	if(l>=r)	return;
	if((l==r-1)||(tot==k))	
	{
		Dow(i,l,r-1)	a[i]=tep,tep--;
		return;
	}
	tot+=2;
	int mid=(l+r)>>1;
	build(l,mid);build(mid,r);
}
int main()
{
	n=read();k=read();
	tot=1;tep=n;
	if(!(k&1))	{puts("-1");return 0;}
	build(0,n);
	if(tot!=k)	puts("-1");else
	For(i,0,n-1)	printf("%d ",a[i]);
}