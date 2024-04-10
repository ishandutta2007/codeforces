#include <bits/stdc++.h>

using namespace std;

int N;
int A[200001];
vector<int> adj[200001];
int seen[200001];
int cv;

void dfs(int u)
{
    if(seen[u]==1)
    {
        cv=u;
        return;
    }
    seen[u]=1;
    dfs(A[u]);
}

void mark(int u)
{
    if(seen[u]==2)
        return;
    seen[u]=2;
    for(auto& v: adj[u])
        mark(v);
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=1; i<=N; i++)
    {
        adj[i].push_back(A[i]);
        adj[A[i]].push_back(i);
    }
    vector<int> one, more;
    for(int i=1; i<=N; i++) if(seen[i]==0)
    {
        dfs(i);
        mark(i);
        if(A[cv]==cv)
            one.push_back(cv);
        else
            more.push_back(cv);
    }
    int ans=0;
    if(one.empty())
    {
        int x=more.back();
        A[x]=x;
        one.push_back(x);
        more.pop_back();
        ans++;
    }
    for(int i=1; i<(int)one.size(); i++)
    {
        A[one[i]]=one[0];
        ans++;
    }
    for(int i=0; i<(int)more.size(); i++)
    {
        A[more[i]]=one[0];
        ans++;
    }
    printf("%d\n", ans);
    for(int i=1; i<=N; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}