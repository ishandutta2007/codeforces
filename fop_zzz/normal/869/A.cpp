#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstring>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
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
int n,a[20001],b[20001],ans;
bool vis[5000001]; 
int main()
{
	n=read();
	For(i,1,n)	a[i]=read(),vis[a[i]]=1;
	For(i,1,n)	b[i]=read(),vis[b[i]]=1;
	For(i,1,n)
		For(j,1,n)	if(vis[a[i]^b[j]])	ans++;
	if(ans&1)	puts("Koyomi");else puts("Karen");
}