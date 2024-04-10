#include <bits/stdc++.h>

using namespace std;

int N, M;
long long ans1, ans2;
vector<int> adj[100001];
bool bip;
int color[100001];
bool seen[100001];
int sz[2], e;

void dfs(int u)
{
    sz[color[u]]++;
    seen[u]=true;
    for(auto& v: adj[u])
    {
        e++;
        if(seen[v])
        {
            if(color[v]!=(color[u]^1))
                bip=false;
        }
        else
        {
            color[v]=color[u]^1;
            dfs(v);
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    if(M==0)
        ans1=3, ans2=1LL*N*(N-1)*(N-2)/6;
    else
    {
        int a, b;
        for(int i=0; i<M; i++)
        {
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bip=true;
        long long tans=0;
        for(int i=1; i<=N; i++) if(!seen[i])
        {
            sz[0]=sz[1]=e=0;
            color[i]=0;
            dfs(i);
            e/=2;
            e-=sz[0]+sz[1]-1;
            tans+=1LL*sz[0]*(sz[0]-1)/2+1LL*sz[1]*(sz[1]-1)/2;
        }
        if(!bip)
            ans1=0, ans2=1;
        else
        {
            bool good=false;
            for(int i=1; i<=N; i++) if(adj[i].size()>=2)
            {
                good=true;
                break;
            }
            if(good)
            {
                ans1=1;
                ans2=tans;
            }
            else
            {
                ans1=2;
                ans2=1LL*(N-2)*M;
            }
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}