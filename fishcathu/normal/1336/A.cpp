#include<cstdio>
#include<algorithm>
const int N=2E5+10;
int read() 
{ 	
    int a=0;char b=1,c; 
    do if((c=getchar())==45)b=-1;while(!(c&16)); 
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16); 
    return a*b; 
} 
void write(int x) 
{
    if(x<0)putchar('-'),x=-x; 
    char a[10],s=0; 
    do a[s++]=x%10|48;while(x/=10); 
    do putchar(a[--s]);while(s);
}
int head[N],next[N<<1],to[N<<1],dis[N],sum[N];
void dfs(int f,int x)
{
	dis[x]=dis[f]+1,sum[x]=1;
	for(int i=head[x];i;i=next[i])if(to[i]!=f)dfs(x,to[i]),sum[x]+=sum[to[i]];
}
int main()
{
	int n=read(),m=read(),s=1;
	long long ans=0;
	for(int i=1,u,v;i<n;++i)next[i<<1]=head[u=read()],to[head[u]=i<<1]=v=read(),next[i<<1|1]=head[v],to[head[v]=i<<1|1]=u;
	dfs(0,1);
	for(int i=1;i<=n;++i)dis[i]-=sum[i];
	std::sort(dis+1,dis+1+n);
	for(int i=0;i<m;++i)ans+=dis[n-i];
	printf("%lld",ans);
}