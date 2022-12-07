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
int n,m,t,sx,sy,tx,ty,ans;
int ct[4],w[4],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
char s[100],cz[200];
bool ok[51][51];
int main()
{
	re(n),re(m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
		{
			if(s[j]!='#')
				ok[i][j]=1;
			if(s[j]=='S')
				sx=i,sy=j;
			if(s[j]=='E')
				tx=i,ty=j;
		}
	}
	scanf("%s",cz+1);
	t=strlen(cz+1);
	for(int i=1;i<=t;++i)
		cz[i]-=48;
	int ans=0;
	for(w[0]=0;w[0]<4;++w[0])
		for(w[1]=0;w[1]<4;++w[1])
			for(w[2]=0;w[2]<4;++w[2])
				for(w[3]=0;w[3]<4;++w[3])
				{
					memset(ct,0,sizeof ct);
					for(int i=0;i<4;++i)
						++ct[w[i]];
					bool okk=1;
					for(int i=0;i<4;++i)
						if(!ct[i])
							okk=0;
					if(!okk)continue;
					int nx=sx,ny=sy;
					bool find=0;
					for(int i=1;i<=t;++i)
					{
						int x=nx+dx[w[cz[i]]],y=ny+dy[w[cz[i]]];
						if(ok[x][y])
						{
							nx=x;
							ny=y;
							if(x==tx && y==ty)find=1;
						}
						else break;
					}
					ans+=find;
				}
	printf("%d\n",ans);
}