#include<cstdio>
#include<iostream>
#define N 2000010
using namespace std;
int nxt[N<<1],to[N<<1],head[N],cnt;
int in[N],out[N],tot;
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    in[v]++;
    out[u]++;
    head[u]=cnt;
}
int id[N],num[N];
int dfs(int u)
{
    int res=id[u]?(1<<(id[u]-1)):0;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        res|=dfs(v);
    }
    return res;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    for(int i=1;i<=n;i++)
    if(!out[i]) id[i]=++tot;
    tot=0;
    for(int i=1;i<=n;i++)
    if(!in[i]) num[++tot]=dfs(i);
    for(int i=1;i<(1<<tot)-1;i++)
    {
		int res=0,res2=0;
        for(int j=1;j<=tot;j++)
        res+=(i&num[j])==num[j],res2+=(i>>(j-1))&1;
		if(res>=res2){puts("NO");return 0;}
    }
    puts("YES");
    return 0;
}