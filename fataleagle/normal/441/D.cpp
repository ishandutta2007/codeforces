#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[3001];
bool seen[3001];
int parent[3001];
vector<int> temp;
vector<pair<int, int> > output;

int find(int u)
{
    if(u!=parent[u])
        parent[u]=find(parent[u]);
    return parent[u];
}

void uni(int u, int v)
{
    parent[find(u)]=find(v);
}

int cycle(int u)
{
    if(seen[u])
        return 0;
    temp.push_back(u);
    seen[u]=true;
    return 1+cycle(A[u]);
}

void disconnect(int u, int v)
{
    memset(seen, 0, sizeof seen);
    vector<int> problem;
    for(int i=1; i<=N; i++)
        if(find(i)==find(u))
            problem.push_back(i), parent[i]=i;
    for(size_t i=0; i<problem.size(); i++)
        if(!seen[problem[i]])
        {
            temp.clear();
            cycle(problem[i]);
            for(size_t i=1; i<temp.size(); i++)
                uni(temp[i], temp[0]);
        }
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), parent[i]=i;
    scanf("%d", &M);
    int totsz=0;
    for(int i=1; i<=N; i++)
        if(!seen[i])
        {
            temp.clear();
            int sz=cycle(i);
            for(size_t i=1; i<temp.size(); i++)
                uni(temp[i], temp[0]);
            totsz+=sz-1;
        }
    int nxt=1;
    while(totsz>M)
    {
        for(int i=nxt+1; i<=N; i++)
            if(find(nxt)==find(i))
            {
                output.push_back(make_pair(nxt, i));
                swap(A[nxt], A[i]);
                disconnect(nxt, i);
                goto good;
            }
        if(nxt==N)
            break;
        nxt++;
        continue;
        good:;
        totsz--;
    }
    while(totsz<M)
    {
        for(int i=nxt+1; i<=N; i++)
            if(find(nxt)!=find(i))
            {
                output.push_back(make_pair(nxt, i));
                uni(nxt, i);
                goto goodb;
            }
        if(nxt==N)
            break;
        nxt++;
        continue;
        goodb:;
        totsz++;
    }
    printf("%d\n", output.size());
    for(size_t i=0; i<output.size(); i++)
        printf("%d %d ", output[i].first, output[i].second);
    printf("\n");
    return 0;
}