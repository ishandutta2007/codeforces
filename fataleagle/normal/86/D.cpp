#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int SZ=450;
int N, M;
int A[200001];
int C[1000001];
long long sum;
pair<int, int> queries[200001];
int order[200001];
long long ans[200001];

bool cmp(int a, int b)
{
    if(queries[a].first/SZ!=queries[b].first/SZ)
        return queries[a].first/SZ<queries[b].first/SZ;
    return queries[a].second<queries[b].second;
}

inline void change_number(int x, int v)
{
    sum-=(long long)C[x]*C[x]*x;
    C[x]+=v;
    sum+=(long long)C[x]*C[x]*x;
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=0; i<M; i++)
        scanf("%d%d", &queries[i].first, &queries[i].second), order[i]=i;
    sort(order, order+M, cmp);
    int L=1, R=1;
    change_number(A[1], 1);
    for(int i=0; i<M; i++)
    {
        int l=queries[order[i]].first;
        int r=queries[order[i]].second;
        while(l<L)
            L--, change_number(A[L], 1);
        while(l>L)
            change_number(A[L], -1), L++;
        while(r<R)
            change_number(A[R], -1), R--;
        while(r>R)
            R++, change_number(A[R], 1);
        ans[order[i]]=sum;
    }
    for(int i=0; i<M; i++)
        printf("%lld\n", ans[i]);
    return 0;
}