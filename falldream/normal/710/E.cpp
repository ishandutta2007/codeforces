#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<cmath>
#include<string.h>
#include<cstdlib>
#define ll long long
#define INF 2e8
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return (ll)x*f;
}
ll s[10000010];
ll n,x,y;
int main()
{
	n=read();
	x=read();
	y=read();
	s[1]=x;
	for(ll i=2;i<=n;i++)
	{
		s[i]=s[i-1]+x;
		if(i%2==0)
		{
			s[i]=min(s[i],s[i/2]+y);
		}
		else
		   s[i]=min(s[i],s[i/2+1]+y+x);
	}
	cout<<s[n];
	return 0;
}