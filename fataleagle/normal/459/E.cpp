#include <bits/stdc++.h>

using namespace std;

int N, M;
struct edge
{
    int u, v, w;
    bool operator< (const edge& other) const
    {
        return w<other.w;
    }
} edges[300000];

int best[300001];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);
    sort(edges, edges+M);
    vector<pair<int, int>> updates;
    for(int i=0, j; i<M;)
    {
        j=i;
        while(j<M && edges[j].w==edges[i].w)
            j++;
        for(int k=i; k<j; k++)
            updates.push_back(make_pair(edges[k].v, best[edges[k].u]+1));
        for(auto it: updates)
            best[it.first]=max(best[it.first], it.second);
        updates.clear();
        i=j;
    }
    printf("%d\n", *max_element(best+1, best+1+N));
    return 0;
}