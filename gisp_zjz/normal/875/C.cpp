#include<bits/stdc++.h>
#define maxn 400020

using namespace std;

vector <int> h[maxn],s[maxn];
queue <int> q;
int d[maxn],a[maxn],m,t,n,ind[maxn],ans[maxn],cnt,inq[maxn];

void add_edge(int u,int v)
{
    h[u].push_back(v);
    ind[v]++;
}

bool solve()
{
    while (!q.empty()) q.pop();
    memset(inq,0,sizeof(inq));
    memset(a,0,sizeof(a));
    for (int i=1;i<=n;i++)
        if (!ind[i]) {q.push(i);inq[i]=1;}
    while (!q.empty())
    {
        int tmp=q.front(); q.pop(); inq[tmp]=2;
        for (int j=0;j<h[tmp].size();j++)
        {
            int tt=h[tmp][j];
            ind[tt]--;
            a[tt]=max(a[tt],a[tmp]+(tt>tmp));
            if (!ind[tt]&&!inq[tt]){
                q.push(tt);
                inq[tt]=1;
            }
        }
    }
    for (int i=1;i<=n;i++)
        if (a[i]>1||!inq[i]) return false;
    return true;
}

int main()
{
    scanf("%d%d",&m,&n);
    for (int i=1;i<=m;i++)
    {
        s[i].clear();
        scanf("%d",&d[i]);
        for (int j=0;j<d[i];j++)
        {
            scanf("%d",&t);
            s[i].push_back(t);
        }
    }
    memset(ind,0,sizeof(ind));
    for (int i=1;i<=n;i++) h[i].clear();
    for (int i=1;i<m;i++)
    {
        int j=0;
        while (j<d[i]&&j<d[i+1]&&s[i][j]==s[i+1][j]) j++;
        if (j==d[i]) continue;
        else if (j==d[i+1]){printf("No\n");return 0;}
        else add_edge(s[i+1][j],s[i][j]);
    }
    if (solve()){
        cnt=0;
        for (int i=1;i<=n;i++)
            if (a[i]) ans[cnt++]=i;
        printf("Yes\n%d\n",cnt);
        for (int i=0;i<cnt;i++) printf("%d ",ans[i]);
        if (cnt) printf("\n");
    }
    else printf("No\n");
    return 0;
}