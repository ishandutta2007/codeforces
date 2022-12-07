#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout); 
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
struct node
{
	int t,d,p,num;
	bool operator < (const node& i)const
	{
		return d<i.d;
	}
}s[101];
int n,cnt,out[101],f[101][2001],x[101][2001],y[101][2001];
bool use[101][2001];
int main()
{
	re(n);
	for(int i=1;i<=n;++i)
		re(s[i].t),re(s[i].d),re(s[i].p),s[i].num=i;
	sort(s+1,s+n+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=2000;++j)
		{
			if(f[i-1][j] > f[i][j-1])f[i][j]=f[i-1][j],x[i][j]=i-1,y[i][j]=j;
			else f[i][j]=f[i][j-1],x[i][j]=i,y[i][j]=j-1;
			if(j>=s[i].t && j<s[i].d && f[i-1][j-s[i].t]+s[i].p>f[i][j])
				f[i][j]=f[i-1][j-s[i].t]+s[i].p,use[i][j]=1,x[i][j]=i-1,y[i][j]=j-s[i].t;
		}
	printf("%d\n",f[n][2000]);
	int i=n,j=2000;
	while(i && j)
	{
		if(use[i][j])out[++cnt]=s[i].num;
		int t=i;
		i=x[t][j],j=y[t][j];
	}
	printf("%d\n",cnt);
	for(int i=cnt;i;--i)
		printf("%d ",out[i]);
}