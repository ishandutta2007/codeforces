#include<iostream>
#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
int n,dfn[2001],low[2001],cnt,a[2001][2001];
stack<int> t;
bool vis[2001];
inline void tarjan(int k)
{
    dfn[k]=low[k]=++cnt;
    vis[k]=1;
    t.push(k);
    for(register int i=1;i<=n;++i)
        if(i!=k&&a[k][i])
            if(!dfn[i])
            {
                tarjan(i);
                low[k]=min(low[k],low[i]);
            }
            else
                if(vis[i])
                    low[k]=min(low[k],dfn[i]);
    if(dfn[k]==low[k])
    {
        int ans=1;
        while(!t.empty()&&t.top()!=k)
        {
            ++ans;
            t.pop();
        }
        t.pop();
        puts(ans==n? "YES":"NO");
        exit(0);
    }
}
int main()
{
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=n;++j)
            scanf("%d",&a[i][j]);
    tarjan(1);
    return 0;
}