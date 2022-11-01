#include <iostream>
#include <cstdio>

using namespace std;

const int MOD=1000000009;
int N;
int A[100002];
pair<int, int> L[100002], R[100002], maxL[100002], maxR[100002];
char ans[100002];
pair<int, int> seg[262144];

pair<int, int> combine(pair<int, int> a, pair<int, int> b)
{
    pair<int, int> ret;
    if(a.first>b.first)
        ret=a;
    else if(a.first<b.first)
        ret=b;
    else
        ret.first=a.first, ret.second=(a.second+b.second)%MOD;
    return ret;
}

void init(int idx, int begin, int end)
{
    if(begin==end)
        seg[idx]=make_pair(-1, 0);
    else
    {
        int mid=(begin+end)/2;
        init(idx*2, begin, mid);
        init(idx*2+1, mid+1, end);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1]);
    }
}

void update(int idx, int begin, int end, int x, pair<int, int> v)
{
    if(x<begin || end<x)
        return;
    if(begin==end)
        seg[idx]=combine(seg[idx], v);
    else
    {
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, x, v);
        update(idx*2+1, mid+1, end, x, v);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1]);
    }
}

pair<int, int> query(int idx, int begin, int end, int i, int j)
{
    if(j<begin || end<i)
        return make_pair(-1, 0);
    if(i<=begin && end<=j)
        return seg[idx];
    int mid=(begin+end)/2;
    return combine(query(idx*2, begin, mid, i, j),
                   query(idx*2+1, mid+1, end, i, j));
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    init(1, 1, 100000);
    for(int i=1; i<=N; i++)
    {
        L[i]=max(query(1, 1, 100000, 1, A[i]-1), make_pair(1, 1));
        update(1, 1, 100000, A[i], make_pair(L[i].first+1, L[i].second));
    }
    init(1, 1, 100000);
    for(int i=N; i>=1; i--)
    {
        R[i]=max(query(1, 1, 100000, A[i]+1, 100000), make_pair(1, 1));
        update(1, 1, 100000, A[i], make_pair(R[i].first+1, R[i].second));
    }
    pair<int, int> maxi=make_pair(-1, 0);
    for(int i=1; i<=N; i++)
        maxi=combine(maxi, L[i]);
    init(1, 1, 100000);
    for(int i=1; i<=N; i++)
    {
        maxL[i]=max(query(1, 1, 100000, 1, A[i]-1), make_pair(0, 1));
        update(1, 1, 100000, A[i], L[i]);
    }
    init(1, 1, 100000);
    for(int i=N; i>=1; i--)
    {
        maxR[i]=max(query(1, 1, 100000, A[i]+1, 100000), make_pair(0, 1));
        update(1, 1, 100000, A[i], R[i]);
    }
    for(int i=1; i<=N; i++)
    {
        if(maxL[i].first+1+maxR[i].first==maxi.first)
        {
            if((long long)maxL[i].second*maxR[i].second%MOD==maxi.second)
                ans[i]='3';
            else
                ans[i]='2';
        }
        else
            ans[i]='1';
    }
    puts(ans+1);
    return 0;
}