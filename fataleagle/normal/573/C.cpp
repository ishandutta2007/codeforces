#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[100001];
int deg[100001];
bool legit[100001];

int main()
{
    scanf("%d", &N);
    int a, b;
    for(int i=1; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> Q;
    for(int i=1; i<=N; i++)
    {
        legit[i]=true;
        deg[i]=adj[i].size();
        if(adj[i].size()==1)
            Q.push(i);
    }
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        legit[u]=false;
        for(auto& v: adj[u]) if(legit[v])
        {
            deg[v]--;
            if(deg[v]==1 && adj[v].size()<=2)
                Q.push(v);
        }
    }
    for(int i=1; i<=N; i++) if(legit[i] && adj[i].size()==3 && deg[i]==1)
        legit[i]=false;
    for(int i=1; i<=N; i++) if(legit[i])
    {
        int cnt=0;
        for(auto& u: adj[i]) if(legit[u])
            cnt++;
        if(cnt>2)
            return printf("No\n"), 0;
    }
    printf("Yes\n");
    return 0;
}