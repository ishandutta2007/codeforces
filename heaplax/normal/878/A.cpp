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
int n,w[11],a=1023,b,c;
int main()
{
	re(n);
	memset(w,-1,sizeof w);
	for(int i=1,x;i<=n;++i)
	{
		char ch=getchar();
		while(ch!='|' && ch!='^' && ch!='&')ch=getchar();
		re(x);
		if(ch=='|')
		{
			for(int c=x,j=1;j<=10;c>>=1,++j)
				if(c&1)	
					w[j]=1;
		}
		if(ch=='^')
		{
			for(int c=x,j=1;j<=10;c>>=1,++j)
				if(c&1)
				{
					if(w[j]==-1)w[j]=2;
					else w[j]^=1;
				}
		}
		if(ch=='&')
		{
			for(int c=x,j=1;j<=10;c>>=1,++j)
				if(!(c&1))w[j]=0;
		}
	}
	for(int i=1;i<=10;++i)
	{
		if(w[i]==0)a^=1<<(i-1);
		if(w[i]==1)b+=1<<(i-1);
		if(w[i]==2)c+=1<<(i-1);
	}
	puts("3");
	printf("& %d\n",a);
	printf("| %d\n",b);
	printf("^ %d\n",c);
}