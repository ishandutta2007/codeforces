#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
#define inf 1e17
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
ll n,k;
inline ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
int main()
{
	n=read();
	k=read();
	ll ned=1;
	For(i,1,k)	ned=ned*10;
	cout<<n*ned/gcd(n,ned)<<endl;
}