#include <bits/stdc++.h>

using namespace std;

struct pt
{
    long long x, y;
    pt operator+ (const pt& other)
    {
        return (pt){x+other.x, y+other.y};
    }
    pt operator- (const pt& other)
    {
        return (pt){x-other.x, y-other.y};
    }
    long long sqdist()
    {
        return x*x+y*y;
    }
    long long dot(const pt& other)
    {
        return x*other.x+y*other.y;
    }
    long long cross(const pt& other)
    {
        return x*other.y-y*other.x;
    }
};

int N, K;
pt A[7];
pt B[1000];
int last[7][1000];
bool anc[7][1000][1000];
int m[7];
vector<int> adj[7];
int seen[7];

bool dfs2(int u)
{
    seen[u]=1;
    for(auto& v: adj[u])
    {
        if(seen[v]==0)
        {
            if(dfs2(v))
                return true;
        }
        else if(seen[v]==1)
            return true;
    }
    seen[u]=2;
    return false;
}

bool dfs(int mask, set<int> s, set<int> t)
{
    int n=__builtin_popcount(mask);
    if(n<(int)s.size())
        return false;
    if(n==0 || s.empty())
    {
        return true;
        for(int i=0; i<K; i++)
            adj[i].clear(), seen[i]=0;
        for(int i=0; i<K; i++) if(m[i]!=-1)
            for(int j=0; j<K; j++) if(i!=j && m[j]!=-1)
                if(anc[i][m[j]][m[i]])
                    adj[j].push_back(i);
        for(int i=0; i<K; i++) if(m[i]!=-1 && seen[i]==0)
            if(dfs2(i))
                return false;
        return true;
    }
    int x=*s.begin();
    s.erase(s.begin());
    for(int i=0; i<K; i++) if((mask>>i)&1)
    {
        m[i]=x;
        set<int> ns=s;
        int z=last[i][x];
        while(z!=-1 && (int)ns.size()<n)
        {
            if(!t.count(z))
                ns.insert(z);
            z=last[i][z];
        }
        t.insert(x);
        if(dfs(mask&~(1<<i), ns, t))
        {
            m[i]=-1;
            return true;
        }
        m[i]=-1;
        t.erase(x);
    }
    return false;
}

int main()
{
    scanf("%d%d", &K, &N);
    for(int i=0; i<K; i++)
        scanf("%lld%lld", &A[i].x, &A[i].y);
    for(int i=0; i<N; i++)
        scanf("%lld%lld", &B[i].x, &B[i].y);
    for(int i=0; i<K; i++)
    {
        for(int j=0; j<N; j++)
        {
            pt l1=B[j]-A[i];
            pair<long long, int> cand=make_pair(0LL, -1);
            for(int k=0; k<N; k++) if(j!=k)
            {
                pt l2=B[k]-A[i];
                if(l1.cross(l2)==0 && l1.dot(l2)>0 && l2.sqdist()<l1.sqdist())
                    cand=max(cand, make_pair(l2.sqdist(), k));
            }
            last[i][j]=cand.second;
        }
    }
    for(int i=0; i<K; i++)
    {
        for(int j=0; j<N; j++)
        {
            int x=j;
            while(x!=-1)
            {
                anc[i][x][j]=true;
                x=last[i][x];
            }
        }
    }
    for(int i=0; i<K; i++)
        m[i]=-1;
    int ans=0;
    set<int> s, t;
    for(int i=0; i<N; i++)
    {
        s.clear();
        s.insert(i);
        if(dfs((1<<K)-1, s, t))
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}