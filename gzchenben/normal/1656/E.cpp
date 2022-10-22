#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,t,F[100005];
vector<int> Edge[100005];
void dfs(int x,int pre,int val)
{
    F[x]=Edge[x].size()*val;
    for(auto &p : Edge[x])
    {
        if(p==pre) continue;
        dfs(p,x,-val);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) Edge[i].clear();
        for(int i=1;i<=n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            Edge[u].push_back(v);
            Edge[v].push_back(u);
        }
        dfs(1,0,1);
        for(int i=1;i<=n;i++) printf("%d ",F[i]);
        printf("\n");
    }
}