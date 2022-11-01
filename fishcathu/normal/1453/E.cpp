#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2E5+10;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
int head[N],nex[N<<1],to[N<<1],dep[N],ans;
void add(int u,int v,int i)
{
	nex[i]=head[u];
	head[u]=i;
	to[i]=v;
}
void dfs(int f,int x)
{
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		if(t==f)continue;
		dfs(x,t);
		dep[x]=min(dep[x],dep[t]+1);
	}
	if(dep[x]==1<<30)dep[x]=1;
	if(f!=1)ans=max(ans,dep[x]+1);
}
int main()
{
 	for(int x=read();x--;)
 	{
 		int n=read(),mx=0,b=0;
 		ans=0;
 		for(int i=1;i<=n;++i)head[i]=0,dep[i]=1<<30;
 		for(int i=1;i<n;++i)
 		{
 			int u=read(),v=read();
			add(u,v,i<<1);
			add(v,u,i<<1|1);	
		}
		for(int i=head[1];i;i=nex[i])
		{
			int t=to[i];
			dfs(1,t);
			if(dep[t]>mx)mx=dep[t],b=0;
			else if(dep[t]==mx)b=1;
		}
		ans=max(ans,mx+b);
		printf("%d\n",ans);
	}
}