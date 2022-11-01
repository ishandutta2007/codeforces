#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
ll n,k,ar=1;
int main()
{
	n=read();k=read();
    if(k>=2) ar+=n*(n-1)/2;
    if(k>=3) ar+=n*(n-1)*(n-2)/3;
    if(k>=4) ar+=n*(n-1)*(n-2)*(n-3)*3/8;
    cout<<ar;
    return 0;
}