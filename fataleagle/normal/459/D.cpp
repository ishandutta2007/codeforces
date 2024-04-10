#include <bits/stdc++.h>

using namespace std;

int N;
int A[1000000];
int B[1000000];
int L[1000000];
int R[1000000];
int seg[4000000];

void update(int idx, int begin, int end, int x, int v)
{
    if(x<begin || end<x)
        return;
    if(begin==end)
        seg[idx]+=v;
    else
    {
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, x, v);
        update(idx*2+1, mid+1, end, x, v);
        seg[idx]=seg[idx*2]+seg[idx*2+1];
    }
}

int query(int idx, int begin, int end, int i, int j)
{
    if(j<begin || end<i)
        return 0;
    if(i<=begin && end<=j)
        return seg[idx];
    int mid=(begin+end)/2;
    return query(idx*2, begin, mid, i, j)+
           query(idx*2+1, mid+1, end, i, j);
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i), B[i]=A[i];
    sort(B, B+N);
    int M=unique(B, B+N)-B;
    for(int i=0; i<N; i++)
        A[i]=lower_bound(B, B+M, A[i])-B+1;
    map<int, int> cnt;
    for(int i=0; i<N; i++)
        L[i]=++cnt[A[i]];
    cnt.clear();
    for(int i=N-1; i>=0; i--)
        R[i]=++cnt[A[i]];
    long long ans=0;
    for(int i=0; i<N; i++)
    {
        ans+=query(1, 1, N, R[i]+1, N);
        update(1, 1, N, L[i], 1);
    }
    printf("%lld\n", ans);
    return 0;
}