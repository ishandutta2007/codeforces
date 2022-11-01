#include <bits/stdc++.h>

using namespace std;

int N;
int A[100000];
int P[100000];
bool ok[100000];
int fa[100000];
long long s[100000];
long long ans[100000];

int find(int u)
{
    if(fa[u]!=u)
        fa[u]=find(fa[u]);
    return fa[u];
}

void merge(int u, int v)
{
    u=find(u), v=find(v);
    fa[u]=v;
    s[v]+=s[u];
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    for(int i=0; i<N; i++)
    {
        scanf("%d", P+i);
        P[i]--;
        fa[i]=i;
    }
    long long rans=0;
    for(int i=N-1; i>=0; i--)
    {
        s[P[i]]=A[P[i]];
        if(P[i]>0 && ok[P[i]-1])
            merge(P[i], P[i]-1);
        if(P[i]+1<N && ok[P[i]+1])
            merge(P[i], P[i]+1);
        ok[P[i]]=true;
        ans[i]=rans;
        rans=max(rans, s[find(P[i])]);
    }
    for(int i=0; i<N; i++)
        printf("%lld\n", ans[i]);
    return 0;
}