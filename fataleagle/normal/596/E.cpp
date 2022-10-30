#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
char grid[200][201];
char S[1000001];
int lastocc[10];
int A[10], B[10];
int C[40000];
vector<int> adj[40000], adj2[40000];
bool seen[40000];
bool seen2[40000];
bool cycle[40000];
int comp[40000];
vector<int> cycnodes[40000];
bool has[40000][10];

bool dfs(int u)
{
    if(seen2[u])
    {
        cycle[u]=true;
        return true;
    }
    seen2[u]=true;
    for(auto& v: adj2[u])
    {
        if(dfs(v))
        {
            if(cycle[u])
                return false;
            cycle[u]=true;
            return true;
        }
    }
    return false;
}

void dfs2(int u, int c)
{
    seen[u]=true;
    comp[u]=c;
    if(cycle[u])
    {
        cycnodes[c].push_back(u);
        has[c][C[u]]=true;
    }
    for(auto& v: adj[u]) if(!seen[v])
        dfs2(v, c);
    for(auto& v: adj2[u]) if(!seen[v])
        dfs2(v, c);
}

bool greedy(int u, int pos)
{
    if(pos>=0 && C[u]==S[pos]-'0')
        pos--;
    if(pos<0)
        return true;
    for(auto& v: adj[u]) if(!cycle[v])
        if(greedy(v, pos))
            return true;
    return false;
}

int main()
{
    scanf("%d%d%d", &N, &M, &Q);
    for(int i=0; i<N; i++)
        scanf("%s", grid[i]);
    for(int i=0; i<10; i++)
        scanf("%d%d", A+i, B+i);
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            int x=i*M+j, y;
            C[x]=grid[i][j]-'0';
            if(i+A[C[x]]>=0 && i+A[C[x]]<N && j+B[C[x]]>=0 && j+B[C[x]]<M)
                y=(i+A[C[x]])*M+(j+B[C[x]]);
            else
                y=x;
            adj[y].push_back(x);
            adj2[x].push_back(y);
        }
    }
    int ncomp=0;
    for(int i=0; i<N*M; i++) if(!seen[i])
    {
        dfs(i);
        dfs2(i, ncomp++);
    }
    for(int i=0; i<Q; i++)
    {
        scanf("%s", S);
        int K=strlen(S);
        memset(lastocc, -1, sizeof lastocc);
        for(int j=0; j<K; j++)
            lastocc[S[j]-'0']=j;
        bool ans=false;
        for(int j=0; !ans && j<ncomp; j++)
        {
            int pos=-1;
            for(int k=0; k<10; k++) if(!has[j][k])
                pos=max(pos, lastocc[k]);
            for(auto& u: cycnodes[j])
                ans|=greedy(u, pos);
        }
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}