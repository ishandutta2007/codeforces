#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define For(i,j,k)	for(register ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(register ll i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
#define eps 1e-8
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=(t*10+c-48),c=getchar();
	return t*f;
}
ll l,r,m,x,y,R,ans;
int main()
{
	r=read();l=r-read();
	m=read();
	For(i,1,m)
	{
		x=read();y=read();R=read();
		ll dis=x*x+y*y;
		if(r-R<0)	continue;
		if(dis>=(l+R)*(l+R)&&dis<=(r-R)*(r-R))	ans++;
	}
	cout<<ans<<endl;
}