#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> adj[100001];
int distA[100001];
int distB[100001];
vector<pair<int, int>> ban[100001];

struct node
{
    int c, u;
    bool operator< (const node& other) const
    {
        return c>other.c;
    }
};

int getBTime(int u, int t)
{
    auto it=lower_bound(ban[u].begin(), ban[u].end(), make_pair(t, 0));
    if(it==ban[u].end() || it->first!=t)
        return t;
    return t+it->second;
}

int main()
{
    scanf("%d%d", &N, &M);
    int a, b, c;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &a);
        while(a--)
        {
            scanf("%d", &b);
            ban[i].push_back({b, 1});
        }
        for(int j=ban[i].size()-2; j>=0; j--)
        {
            if(ban[i][j].first+1==ban[i][j+1].first)
                ban[i][j].second=ban[i][j+1].second+1;
        }
    }
    memset(distA, 0x3f, sizeof distA);
    memset(distB, 0x3f, sizeof distB);
    priority_queue<node> pq;
    distA[1]=0;
    distB[1]=getBTime(1, distA[1]);
    pq.push({distB[1], 1});
    while(!pq.empty())
    {
        int c=pq.top().c;
        int u=pq.top().u;
        pq.pop();
        if(c!=distB[u])
            continue;
        for(auto& it: adj[u])
        {
            int v=it.first;
            int w=it.second;
            distA[v]=min(distA[v], c+w);
            int tmp=getBTime(v, c+w);
            if(tmp<distB[v])
            {
                distB[v]=tmp;
                pq.push({distB[v], v});
            }
        }
    }
    if(distA[N]>=0x3f3f3f3f)
        printf("-1\n");
    else
        printf("%d\n", distA[N]);
    return 0;
}