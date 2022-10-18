#include<iostream>
#include<cstdio>
#include<stack>
#include<ctime>
#include<string>
using namespace std;
struct edge
{
    int nxt,to;
}e[500001<<3];
int n,tot,h[500001<<1],node[500001][2];
bool vis[500001<<1],col[500001<<1];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs(int k,int color)
{
    vis[k]=1;
    col[k]=color;
    for(register int i=h[k];i;i=e[i].nxt)
        if(!vis[e[i].to])
            dfs(e[i].to,color^1);
}
int main()
{
    n=read();
    for(register int i=1;i<=n;++i)
    {
        add((i<<1)-1,i<<1);
        add(i<<1,(i<<1)-1);
    }
    for(register int i=1;i<=n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
        node[i][0]=x;
        node[i][1]=y;
    }
    for(register int i=1;i<=n<<1;++i)
        if(!vis[i])
            dfs(i,0);
    for(register int i=1;i<=n;++i)
        printf("%d %d\n",col[node[i][0]]+1,col[node[i][1]]+1);
    puts("");
    return 0;
}