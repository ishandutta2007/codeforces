#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(ll i=k;i>=j;--i)
#define ll long long
#define mk make_pair
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
ll ans,tmp=0,n,l,v[20001];
int main()
{
	n=read();l=read();
	For(i,1,32)	v[i]=5e18;
	For(i,1,n)	v[i]=read();
	For(i,1,32)	For(j,1,i-1)	v[i]=min(v[i],v[j]*(1LL<<(i-j)));
	ll ans=5e18;
	Dow(i,1,32)
	{
		if(l&(1<<i-1))	tmp=tmp+v[i];
		else	ans=min(ans,tmp+v[i]);
	}
	ans=min(ans,tmp);
	cout<<ans<<endl;
}