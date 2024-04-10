#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define N 100010
bool vis[N];

struct note
{
    int v,next;
}edge[N*3];
int head[N],kk;

void add(int from,int to)
{
    edge[kk].next = head[from];
    edge[kk].v = to;
    head[from] = kk++;
}
int cnt;
void dfs(int root)
{
    if(vis[root]) return ;
    cnt++;
    vis[root] = 1;
    for(int i = head[root];i != -1;i = edge[i].next)
        dfs(edge[i].v);
}
int main()
{
    int n,m,p;
    cin >> n >> m >> p;
    int a,b;
    kk = 1;memset(head,-1,sizeof(head));
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d",&a,&b);
        add(a,b);add(b,a);
    }
    memset(vis,0,sizeof(vis));
    long long sum = 0,re = 1;
    int k = 0;
    for(int i = 1;i <= n;i++)
    {
        if(vis[i] == 0)
        {
            cnt = 0;
            dfs(i);
            k++;
            sum = (sum + cnt)%p;
            re = (re * cnt)%p;
        }
    }
    for(int i = 1;i <= k-2;i++) re = (re * sum)%p;
    if(k == 1) cout << 1%p << "\n";
    else cout << re << "\n";
    return 0;
}