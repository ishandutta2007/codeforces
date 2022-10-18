#include<iostream>
#include<cstdio>
using namespace std;
int n,a[200001],ch[200001*30][2],tot;
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
inline void insert(int x)
{
    int node=1;
    for(register int i=30;~i;--i)
    {
        if(!ch[node][(x>>i)&1])
            ch[node][(x>>i)&1]=++tot;
        node=ch[node][(x>>i)&1];
    }
}
int dfs(int k)
{
    if(!ch[k][0]&&!ch[k][1])
        return 1;
    if(!ch[k][1])
        return dfs(ch[k][0]);
    if(!ch[k][0])
        return dfs(ch[k][1]);
    return max(dfs(ch[k][0]),dfs(ch[k][1]))+1;
}
int main()
{
    n=read();
    tot=1;
    for(register int i=1;i<=n;++i)
    {
        a[i]=read();
        insert(a[i]);
    }
    printf("%d\n",n-dfs(1));
    return 0;
}