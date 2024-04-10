#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int N, M;
int A[500001];
int L[500001];
map<int, int> last;
vector<pair<int, int>> queries[500001];
int ans[500001];
int seg[1048576];

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

int query(int idx, int begin, int end, int i, int j)
{
    if(j<begin || end<i)
        return 0x3f3f3f3f;
    if(i<=begin && end<=j)
        return seg[idx];
    int mid=(begin+end)/2;
    return min(query(idx*2, begin, mid, i, j),
               query(idx*2+1, mid+1, end, i, j));
}

int main()
{
    memset(seg, 0x3f, sizeof seg);
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", A+i);
        L[i]=last[A[i]];
        last[A[i]]=i;
    }
    int a, b;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        queries[b].push_back({a, i});
    }
    for(int i=1; i<=N; i++)
    {
        if(L[i])
            update(1, 1, N, L[i], i-L[i]);
        for(auto& it: queries[i])
            ans[it.second]=query(1, 1, N, it.first, i);
    }
    for(int i=0; i<M; i++)
        printf("%d\n", ans[i]==0x3f3f3f3f?-1:ans[i]);
    return 0;
}