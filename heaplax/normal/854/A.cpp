#include<map>
#include<set>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
void re(int& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(47<ch)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x=-x;
}
using namespace std;
int n;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int main()
{
	re(n);
	for(int i=n/2+(n&1);i<=n;++i)
		if(gcd(i,n-i) == 1)
		{
			printf("%d %d\n",n-i,i);
			return 0;
		}
}