#include<bits/stdc++.h>
#define maxn 520300

using namespace std;
vector<int> h[maxn];
int a[maxn],d[maxn],c[maxn],n,r,s;

void dfs(int fa,int u)
{
    if (d[r]<d[u]) r=u;
    for (int i=0;i<h[u].size();i++)
    {
        int v=h[u][i];
        if (v!=fa) d[v]=d[u]+1,dfs(u,v);
    }
}

int dfs2(int fa,int u)
{
    int t=0;
    for (int i=0;i<h[u].size();i++)
    {
        int v=h[u][i];
        if (v!=fa) t=max(t,dfs2(u,v));
    }
    c[t]--;c[t+1]++;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        h[u].push_back(v);
        h[v].push_back(u);
    }
    r=1;dfs(0,1);
    int m=dfs2(0,r); r=0; s=0;a[0]=1;
    for (int i=n;i;i--)
        for (int j=0;j<c[i];j++)
            s+=i,a[++r]=s;
    for (int i=r+1;i<n;i++) a[i]=n;
    for (int i=0;i<n;i++) printf("%d ",a[i]); printf("\n");
    return 0;
}