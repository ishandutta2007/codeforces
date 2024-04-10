#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[200001];
set<int> S[200001];
int deg[200001];
bool active[200001];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N-1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for(int i=1; i<=N; i++)
        active[i]=true;
    queue<int> Q;
    for(int i=1; i<=N; i++) if(deg[i]==1)
    {
        Q.push(i);
        S[i].insert(0);
    }
    for(int i=0; i<N-1 && !Q.empty(); i++)
    {
        int u=Q.front();
        Q.pop();
        if(S[u].size()!=1)
            continue;
        active[u]=false;
        deg[u]--;
        int x=*S[u].begin();
        for(auto& v: adj[u]) if(deg[v]>=1)
        {
            S[v].insert(x+1);
            if(--deg[v]==1)
                Q.push(v);
        }
    }
    int nactive=0;
    for(int i=1; i<=N; i++) if(active[i])
        nactive++;
    int ans;
    if(nactive==1)
    {
        ans=0;
        for(int i=1; i<=N; i++) if(active[i])
        {
            if(S[i].size()>2)
            {
                ans=-1;
                break;
            }
            for(auto& it: S[i])
                ans+=it;
        }
        while(ans>0 && ans%2==0)
            ans/=2;
    }
    else
        ans=-1;
    printf("%d\n", ans);
    return 0;
}