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
ll a,b;
int main()
{
	a=read();b=read();
	ll now=1;
	For(i,a+1,b)
	{
		ll ned=i%10;
		if(ned==0)	{now=0;break;}
			else now=now*ned%10;
	}
	cout<<now<<endl;
}