#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#define ll long long
#define INF 2000000000
using namespace std;

ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll xx,yy,x2,y2,k;
int main()
{ 
    xx=read();
    yy=read();
    x2=read();
    y2=read();
    k=read();
    xx=max(xx,x2);
    yy=min(yy,y2);
	if(xx>yy)
	{
		puts("0");
		return 0;
	}
	if(xx<=k&&yy>=k)
	   xx++;
	cout<<yy-xx+1;
	return 0;
}