#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int N, M, K, Q;
pair<int, int> A[200000];
bool ans[200000];
int seg[524288];

struct query
{
    int x0, y0, x1, y1, i;
    bool operator< (const query& other) const
    {
        return x1<other.x1;
    }
} B[200000];

void update(int idx, int begin, int end, int x, int v)
{
    if(x<begin || end<x)
        return;
    if(begin==end)
        seg[idx]=v;
    else
    {
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, x, v);
        update(idx*2+1, mid+1, end, x, v);
        seg[idx]=min(seg[idx*2], seg[idx*2+1]);
    }
}

int query(int idx, int begin, int end, int l, int r)
{
    if(r<begin || end<l)
        return 0x3f3f3f3f;
    if(l<=begin && end<=r)
        return seg[idx];
    int mid=(begin+end)/2;
    return min(query(idx*2, begin, mid, l, r),
               query(idx*2+1, mid+1, end, l, r));
}

void solve()
{
    memset(seg, 0, sizeof seg);
    sort(A, A+K);
    sort(B, B+Q);
    for(int i=0, j=0; i<Q; i++)
    {
        for(; j<K && A[j].first<=B[i].x1; j++)
            update(1, 1, M, A[j].second, A[j].first);
        ans[B[i].i]|=query(1, 1, M, B[i].y0, B[i].y1)>=B[i].x0;
    }
}

int main()
{
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    for(int i=0; i<K; i++)
        scanf("%d%d", &A[i].first, &A[i].second);
    for(int i=0; i<Q; i++)
        scanf("%d%d%d%d", &B[i].x0, &B[i].y0, &B[i].x1, &B[i].y1), B[i].i=i;
    solve();
    swap(N, M);
    for(int i=0; i<K; i++)
        swap(A[i].first, A[i].second);
    for(int i=0; i<Q; i++)
    {
        swap(B[i].x0, B[i].y0);
        swap(B[i].x1, B[i].y1);
    }
    solve();
    for(int i=0; i<Q; i++)
    {
        if(ans[i])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}