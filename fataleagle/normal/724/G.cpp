#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;

struct edge
{
    int u, v;
    long long c;
};

int N, M;
int fa[100001];
vector<pair<int, long long>> adj[100001];
vector<edge> e[100001];
long long X[100001];
vector<long long> xors;

int powmod(int a, int b)
{
    int ret=1;
    for(; b>0; b/=2)
    {
        if(b&1)
            ret=1LL*ret*a%MOD;
        a=1LL*a*a%MOD;
    }
    return ret;
}

int find(int u)
{
    if(u!=fa[u])
        fa[u]=find(fa[u]);
    return fa[u];
}

bool merge(int u, int v)
{
    u=find(u), v=find(v);
    if(u==v)
        return false;
    fa[u]=v;
    return true;
}

void dfs(int u, int p, long long x)
{
    X[u]=x;
    xors.push_back(x);
    for(auto& it: adj[u])
    {
        int v=it.first;
        long long c=it.second;
        if(v==p)
            continue;
        dfs(v, u, x^c);
    }
}

int solve(int u)
{
    xors.clear();
    dfs(u, u, 0LL);
    vector<long long> v;
    for(auto& it: e[u])
        v.push_back(X[it.u]^X[it.v]^it.c);
    int r=0;
    for(int i=0; i<63 && i<(int)v.size(); i++)
    {
        for(int j=r; j<(int)v.size(); j++) if((v[j]>>i)&1)
        {
            swap(v[j], v[r]);
            break;
        }
        if(!((v[r]>>i)&1))
            continue;
        for(int j=0; j<(int)v.size(); j++) if(r!=j) if((v[j]>>i)&1)
            v[j]^=v[r];
        r++;
    }
    //for(auto& it: v)
        //cout<<bitset<6>(it)<<endl;
    //cout<<endl;
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end())-v.begin());
    //for(auto& it: v)
        //cout<<bitset<6>(it)<<endl;
    int positive=0;
    for(int i=0; i<(int)v.size(); i++)
        positive+=v[i]>0;
    int ways=1;
    if(positive>0)
        ways=powmod(2, positive-1);
    int ret=0;
    for(int i=0; i<63; i++)
    {
        bool good=false;
        for(int j=0; j<(int)v.size(); j++) if((v[j]>>i)&1)
        {
            good=true;
            break;
        }
        int cnt[2]={0, 0};
        for(auto& it: xors)
            cnt[(it>>i)&1]++;
        int zero=((1LL*cnt[0]*cnt[0]+1LL*cnt[1]*cnt[1]-cnt[0]-cnt[1])/2)%MOD;
        int one=1LL*cnt[0]*cnt[1]%MOD;
        if(good)
            ret=(ret+1LL*ways*(zero+one)%MOD*powmod(2, i))%MOD;
        else
            ret=(ret+1LL*powmod(2, positive)*one%MOD*powmod(2, i))%MOD;
    }
    return ret;
}

vector<pair<int, long long>> adj2[10];
bool dp[10][10][1<<6];

void go(int b, int u, int x)
{
    if(dp[b][u][x])
        return;
    dp[b][u][x]=true;
    for(auto& it: adj2[u])
        go(b, it.first, x^it.second);
}

int main()
{
    //freopen("in2.txt", "r", stdin);
    while(~scanf("%d%d", &N, &M))
    {
        xors.clear();
        for(int i=1; i<=N; i++)
            adj[i].clear(), e[i].clear(), X[i]=0;
        for(int i=1; i<=N; i++)
            fa[i]=i;

        vector<edge> inp;

        vector<edge> edges;
        int a, b;
        long long c;
        for(int i=0; i<M; i++)
        {
            scanf("%d%d%lld", &a, &b, &c);
            /*
            inp.push_back({a, b, c});
            adj2[a].push_back({b, c});
            adj2[b].push_back({a, c});
            */
            if(merge(a, b))
            {
                adj[a].push_back({b, c});
                adj[b].push_back({a, c});
            }
            else
                edges.push_back({a, b, c});
        }
        for(auto& it: edges)
            e[find(it.u)].push_back(it);

        /*
        memset(dp, 0, sizeof dp);
        for(int i=1; i<=N; i++)
            go(i, i, 0LL);
        int rans=0;
        for(int i=1; i<=N; i++)
            for(int j=i+1; j<=N; j++)
                for(int k=0; k<(1<<6); k++) if(dp[i][j][k])
                    rans=(rans+k)%MOD;
        printf("%d\n", rans);
        */

        int ans=0;
        for(int i=1; i<=N; i++) if(fa[i]==i)
            ans=(ans+solve(i))%MOD;
        printf("%d\n", ans);
        /*
        if(ans!=rans)
        {
            printf("!!!\n");
            printf("%d %d\n", N, M);
            for(auto& it: inp)
                printf("%d %d %lld\n", it.u, it.v, it.c);
        }
        assert(ans==rans);
        */
    }
    //printf("all ok\n");
    return 0;
}