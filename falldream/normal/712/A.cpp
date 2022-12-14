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

int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll n,o=0,e=0;
ll a[100010];
ll b[100010];
int main()
{
	n=read();
    for(int i=1;i<=n;i++)
    {
    	a[i]=read();
    }
	for(int i=n;i>=1;i--)
	{
		if(i&1)
		{
			b[i]=a[i]-o+e;
			o+=b[i];
		}
		else
		{
			b[i]=a[i]-e+o;
			e+=b[i];
		}
	}
	for(int i=1;i<=n;i++)
	    cout<<b[i]<<" ";
	return 0;
}