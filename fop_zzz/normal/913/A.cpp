#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<algorithm>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=t*10+c-48,c=getchar();
    return t*f;
}
int n,m;
int main()
{
	n=read();m=read();
	int ret=1;
	For(i,1,n)
	{
		ret=ret*2; 
		if(ret>m) 
		{
			printf("%d\n", m); return 0; 
		}
	}
	printf("%d\n", m%ret);
	return 0;
}