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
#define eps 1e-8
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
int x,y;
int main()
{
	y=read();x=read();
	if(x==1&&y!=0)	return puts("No"),0;
	if(x==0)	return puts("No"),0;
	x--;
	if(x>y)	return puts("No"),0;
	if((y-x)&1)	puts("No");else puts("Yes");
}