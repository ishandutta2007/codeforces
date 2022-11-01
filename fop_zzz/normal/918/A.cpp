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
int n,f[20001];
bool vis[5001];
int main()
{
	n=read();
	f[1]=1;f[2]=1;vis[1]=1;
	int now=3;
	while(1)
	{
		f[now]=f[now-1]+f[now-2];
		vis[f[now]]=1;
		if(f[now]>n)	break;
		now++;
	}
	For(i,1,n)	if(vis[i])	putchar('O');else putchar('o');
}