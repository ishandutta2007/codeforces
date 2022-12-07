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
#define N 5555
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
int n,ans,t[N],d[N],a[N],b[N],out[N];
bool have[N];
int main()
{
	re(n);
	for(int i=0;i<n;++i)
	{
		printf("? %d %d\n",i,i);
		fflush(stdout);
		re(t[i]);
		if(i!=n-1)
		{
			printf("? %d %d\n",i,i+1);
			fflush(stdout);
			re(d[i]);
		}
	}
	for(int i=0;i<n;++i)
	{
		a[0]=i;b[0]=t[0]^a[0];
		bool ok=1;
		for(int j=1;j<n;++j)
		{
			b[j]=d[j-1]^a[j-1];
			a[j]=t[j]^b[j];
		}
		memset(have,0,sizeof have);
		for(int j=0;j<n;++j)
			if(a[j]>=n || have[a[j]])ok=0;
			else have[a[j]]=1;
		memset(have,0,sizeof have);
		for(int j=0;j<n;++j)
			if(b[j]>=n || have[b[j]] || a[b[j]]!=j)ok=0;
			else have[b[j]]=1;	
		if(ok)
		{
			++ans;
			for(int j=0;j<n;++j)
				out[j]=a[j];
		}
	}
	puts("!");
	printf("%d\n",ans);
	if(ans)
		for(int i=0;i<n;++i)
			printf("%d ",out[i]);
}
/*
a[0]^b[0]=t[0]
b[0]=t[0]^a[0]
*/