#include<bits/stdc++.h>
#define maxn 205030

using namespace std;
typedef long long ll;
struct pi{
    ll x,y;
    bool operator <(pi const &u) const{
        return y>u.y;
    }
};

vector <pi> h[maxn];
int n,m;
ll ans[maxn],b[maxn];
bool vis[maxn];
priority_queue <pi> q;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        ll u,v,w;
        scanf("%I64d%I64d%I64d",&u,&v,&w); w=w*2;
        h[u].push_back({v,w});
        h[v].push_back({u,w});
    }
    for (int i=1;i<=n;i++) scanf("%lld",&ans[i]);
    for (int i=1;i<=n;i++) q.push({i,ans[i]});
    memset(vis,0,sizeof(vis));
    while (!q.empty())
    {
        pi tmp=q.top(); q.pop();
        ll u=tmp.x;
        if (vis[u]) continue; vis[u]=true;
        for (int i=0;i<h[u].size();i++)
        {
            ll v=h[u][i].x;
            if (ans[v]>ans[u]+h[u][i].y){
                ans[v]=ans[u]+h[u][i].y;
                q.push({v,ans[v]});
            }
        }
    }
    for (int i=1;i<=n;i++) printf("%I64d ",ans[i]);
    printf("\n");
    return 0;
}