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
#define LL long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
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
pair<int,int> d[62];
int n;
int m,a[32],use[32][64][2048];
bool f[32][64][2048],edge[64][64];
int main()
{
	re(m);
	for(int i=1;i<=m;++i)re(a[i]);
	sort(a+1,a+m+1);
	f[0][0][0]=1;
	for(int i=1;i<=m;++i)
		for(int j=i;j<=61;++j)
			for(int k=j*(j-1)/2;k<=2000;++k)
				for(int l=1;l<=j && l*a[i]<=k;++l)if(f[i-1][j-l][k-l*a[i]])
				{
					f[i][j][k]=1;
					use[i][j][k]=l;
					break;
				}
	for(int i=1;i<=61;++i)
		if(f[m][i][i*(i-1)/2])
		{
			printf("%d\n",i);
			int a=m,b=i,c=i*(i-1)/2;
			while(a)
			{
				int t=use[a][b][c];
				for(int j=1;j<=t;++j)
					d[++n].first=::a[a],d[n].second=n;
				c-=t*::a[a];b-=t;--a;
			}
			for(int j=1;j<=n;++j)
			{
				sort(d+j,d+n+1);
				for(int k=j+1;k<=j+d[j].first;++k)
					edge[d[j].second][d[k].second]=1;
				for(int k=j+d[j].first+1;k<=n;++k)
					edge[d[k].second][d[j].second]=1,
					--d[k].first;
				d[j].first=0;
			}
			for(int j=1;j<=n;++j,puts(""))
				for(int k=1;k<=n;++k)
					printf("%d",edge[j][k]);
			return 0;
		}
	puts("-1");
}