#include <bits/stdc++.h>

using namespace std;

int N, M, W;
vector<int> adj[5001];
vector<pair<int, int>> m[5001];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    scanf("%d", &W);
    for(int i=0; i<W; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        m[a].push_back({b, c});
    }
    int Q;
    scanf("%d", &Q);
    while(Q--)
    {
        int g, r, a;
        scanf("%d%d%d", &g, &r, &a);
        vector<int> seen(N+1, -1);
        queue<int> q;
        q.push(g);
        seen[g]=0;
        multiset<pair<int, int>> s;
        long long tot=0, cost=0;
        while(!q.empty())
        {
            g=q.front();
            q.pop();
            for(auto& it: m[g])
                s.insert({it.second, it.first}), tot+=it.first, cost+=1LL*it.first*it.second;
            while(!s.empty() && tot-((--s.end())->second)>=r)
                cost-=1LL*(--s.end())->first*(--s.end())->second, tot-=(--s.end())->second, s.erase(--s.end());
            if(tot>=r)
            {
                if(cost-(tot-r)*(--s.end())->first<=a)
                {
                    printf("%d\n", seen[g]);
                    goto ok;
                }
            }
            for(auto& v: adj[g]) if(seen[v]==-1)
            {
                seen[v]=seen[g]+1;
                q.push(v);
            }
        }
        printf("-1\n");
        ok:;
    }
    return 0;
}