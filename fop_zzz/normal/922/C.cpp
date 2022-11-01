#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<map>
#include<algorithm>
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define Dow(i,j,k)  for(ll i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define eps 1e-8
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
ll n,k,tmp;
map<ll,int> vis;
int main()
{
	n=read();k=read();
	For(i,1,k)
	{
		int tmp=n%i;
		if(vis[tmp])	return puts("NO"),0;
		vis[tmp]=1;
	}
	puts("Yes");
}