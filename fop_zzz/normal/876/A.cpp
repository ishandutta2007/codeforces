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
int n,x,y,z,q[4][4],to[4],ans;
int main()
{
	n=read();x=read();y=read();z=read();
	q[1][2]=q[2][1]=x;q[1][3]=q[3][1]=y;q[2][3]=q[3][2]=z;
	if(z>y)	to[3]=1;else to[3]=2;
	if(z>x)	to[2]=1;else to[2]=3;
	if(x>y)	to[1]=3;else to[1]=2;
	int t=1;
	For(i,1,n-1)
	{
		ans+=q[t][to[t]];
		t=to[t];
	}
	printf("%d\n",ans);
}