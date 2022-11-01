#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <cstring>
#include <ctime>
#include <vector>
#define inf 1e9
#define ll long long
#define For(i,j,k) for(int i=j;i<=k;i++)
#define Dow(i,j,k) for(int i=k;i>=j;i--)
using namespace std;
inline int read(){   int x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){write(x);puts("");}
double d,k;
int n;
int main()
{
	scanf("%d%lf",&n,&k);
	double z=(n-2)*180.0/(double)n;
	double del=z/(double)(n-2);
	double now=0;
	double ans=1e9;
	printf("2 1");
	int p=2;
	int ans1=0;
	For(i,1,n-2)
	{
		p++;
		now+=del;
		if(abs(now-k)<ans)	ans=abs(now-k),ans1=p;
	}
	printf(" %d",ans1);
}