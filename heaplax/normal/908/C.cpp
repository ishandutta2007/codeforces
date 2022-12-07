#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 1001
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
const double pi=acos(-1);
int n;
double r;
double x[N],y[N];
int main()
{
	re(n);
	scanf("%lf",&r);
	for(int i=1;i<=n;++i)scanf("%lf",&x[i]);
	for(int i=1;i<=n;++i)
	{
		y[i]=r;
		for(int j=1;j<i;++j)
		{
			double t=fabs(x[i]-x[j]);
			if(2*r>=t)
			{
				double e=sqrt((4*r*r-t*t))+y[j];
				y[i]=max(y[i],e);
			}
		}
	}
	for(int i=1;i<=n;++i)
		printf("%.10lf ",y[i]);
}