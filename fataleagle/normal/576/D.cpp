#include <bits/stdc++.h>

using namespace std;

int N, M;

struct edge
{
    int a, b, d;
    bool operator< (const edge& other) const
    {
        return d<other.d;
    }
} A[150];

struct matrix
{
    int data[150][150];
    matrix operator* (const matrix& o) const
    {
        matrix ret;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                ret.data[i][j]=0;
        for(int i=0; i<N; i++)
            for(int k=0; k<N; k++) if(data[i][k])
                for(int j=0; j<N; j++)
                    ret.data[i][j]+=data[i][k]*o.data[k][j];
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                ret.data[i][j]=!!ret.data[i][j];
        return ret;
    }
} graph, pos, cost;

int dist[150];
bool seen[150];

int dijkstra()
{
    for(int i=0; i<N; i++)
    {
        if(pos.data[i][0])
            dist[i]=0;
        else
            dist[i]=0x3f3f3f3f;
        seen[i]=false;
    }
    while(1)
    {
        int idx=-1;
        for(int i=0; i<N; i++) if(!seen[i] && (idx==-1 || dist[i]<dist[idx]))
            idx=i;
        if(idx==-1 || dist[idx]==0x3f3f3f3f)
            break;
        seen[idx]=true;
        for(int i=0; i<N; i++) if(graph.data[i][idx])
            dist[i]=min(dist[i], dist[idx]+1);
    }
    return dist[N-1];
}

matrix power(matrix a, int b)
{
    matrix ret;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            ret.data[i][j]=i==j;
    while(b)
    {
        if(b&1)
            ret=ret*a;
        a=a*a;
        b/=2;
    }
    return ret;
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
    {
        int a, b, d;
        scanf("%d%d%d", &a, &b, &d);
        A[i].a=a-1;
        A[i].b=b-1;
        A[i].d=d;
    }
    sort(A, A+M);
    pos.data[0][0]=1;
    int ans=dijkstra();
    int cur=0;
    for(int i=0, j; i<M; i=j)
    {
        matrix tmp=power(graph, A[i].d-cur);
        pos=tmp*pos;
        for(int k=0; k<N; k++)
            for(int l=1; l<N; l++)
                pos.data[k][l]=0;
        for(j=i; j<M && A[j].d==A[i].d; j++)
        {
            int u=A[j].a;
            int v=A[j].b;
            graph.data[v][u]=1;
        }
        ans=min(ans, A[i].d+dijkstra());
        cur=A[i].d;
    }
    if(ans>=0x3f3f3f3f)
        printf("Impossible\n");
    else
        printf("%d\n", ans);
    return 0;
}