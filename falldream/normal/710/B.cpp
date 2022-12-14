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
	return x*f;
}
int n;
int s[300010];
double m=0;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
	    s[i]=read();
    }
    sort(s+1,s+n+1);
    if(n&1)
       cout<<s[n/2+1];
    else
       cout<<s[n/2];
	return 0;
}