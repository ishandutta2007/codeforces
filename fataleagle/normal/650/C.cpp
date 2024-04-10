#include <bits/stdc++.h>

using namespace std;

struct info
{
    int x, y, v, g, i;
    bool operator< (const info& other) const
    {
        return v<other.v;
    }
};

int N, M;
vector<info> A;
vector<int> maxR;
vector<int> maxC;
vector<vector<int>> ans;
vector<int> par;

int find(int u)
{
    if(u!=par[u])
        par[u]=find(par[u]);
    return par[u];
}

void merge(int u, int v)
{
    par[find(u)]=find(v);
}

int main()
{
    scanf("%d%d", &N, &M);
    maxR.resize(N);
    maxC.resize(M);
    ans.resize(N, vector<int>(M));
    par.resize(N*M);
    for(int i=0; i<N*M; i++)
        par[i]=i;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            int a;
            scanf("%d", &a);
            A.push_back((info){i, j, a, -1, i*M+j});
        }
    }
    sort(A.begin(), A.end());
    for(int i=0, j; i<(int)A.size(); i=j)
    {
        for(j=i; j<(int)A.size() && A[i].v==A[j].v; j++);
        sort(A.begin()+i, A.begin()+j, [](const info& a, const info& b) {
            return a.x<b.x;
        });
        for(int x=i, y; x<j; x=y)
            for(y=x; y<j && A[x].x==A[y].x; y++)
                merge(A[x].i, A[y].i);
        sort(A.begin()+i, A.begin()+j, [](const info& a, const info& b) {
            return a.y<b.y;
        });
        for(int x=i, y; x<j; x=y)
            for(y=x; y<j && A[x].y==A[y].y; y++)
                merge(A[x].i, A[y].i);
        for(int k=i; k<j; k++)
            A[k].g=find(A[k].i);
        sort(A.begin()+i, A.begin()+j, [](const info& a, const info& b) {
            return a.g<b.g;
        });
    }
    for(int i=0, j; i<(int)A.size(); i=j)
    {
        int maxi=0;
        for(j=i; j<(int)A.size() && A[i].g==A[j].g; j++)
        {
            maxi=max(maxi, maxR[A[j].x]);
            maxi=max(maxi, maxC[A[j].y]);
        }
        int v=maxi+1;
        for(j=i; j<(int)A.size() && A[i].g==A[j].g; j++)
        {
            maxR[A[j].x]=v;
            maxC[A[j].y]=v;
            ans[A[j].x][A[j].y]=v;
        }
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            printf("%d%c", ans[i][j], " \n"[j==M-1]);
    return 0;
}