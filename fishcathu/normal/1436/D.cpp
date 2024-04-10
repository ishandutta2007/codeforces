#include<cstdio>
typedef long long ll;
const int N=2E5+1;
int read() 
{ 	
    int a=0;char b=1,c; 
    do if((c=getchar())==45)b=-1;while(!(c&16)); 
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16); 
    return a*b; 
}
int head[N],next[N],sm[N];ll max[N],sum[N];
void dfs(int u)
{
    for(int v=head[u];v;v=next[v])
    {
        dfs(v),sum[u]+=sum[v],sm[u]+=sm[v];
        if(max[v]>max[u])max[u]=max[v];
    }
    if(!sm[u])sm[u]=1,max[u]=sum[u];
    if(sum[u]>max[u]*sm[u])max[u]=sum[u]%sm[u]?sum[u]/sm[u]+1:sum[u]/sm[u];
}
int main()
{
    int n=read();
    for(int i=2,u;i<=n;++i)next[i]=head[u=read()],head[u]=i;
    for(int i=1;i<=n;++i)sum[i]=read();
    dfs(1),printf("%lld",max[1]);
    return 0;
}