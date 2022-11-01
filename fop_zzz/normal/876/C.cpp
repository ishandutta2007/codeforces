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
int n,sum,kk,z[2000],d;
int main(){
	n=read();
	for (int i=max(n-200,0);i<=n;i++)
	{
		sum=i;kk=i;while (kk)sum+=kk%10,kk/=10;
		if (sum==n)z[++d]=i;
	}
	printf("%d\n",d);
	for (int i=1;i<=d;i++)	printf("%d\n",z[i]);
}