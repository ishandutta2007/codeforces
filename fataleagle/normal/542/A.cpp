#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N, M;
struct commercial
{
    int l, r, i, lc, rc;
} A[200001];
struct channel
{
    int l, r, w, i, lc, rc;
} B[200001];

bool cmp0(const commercial& a, const commercial& b)
{
    return a.l<b.l;
}

bool cmp1(const channel& a, const channel& b)
{
    return a.l<b.l;
}

bool cmp2(const commercial& a, const commercial& b)
{
    return a.r<b.r;
}

bool cmp3(const channel& a, const channel& b)
{
    return a.r<b.r;
}

pair<int, int> bit[1000001];

pair<int, int> query(int x)
{
    pair<int, int> ret=make_pair(-0x3f3f3f3f, -1);
    for(x++; x>0; x-=x&-x)
        if(bit[x].first>ret.first)
            ret=bit[x];
    return ret;
}

void update(int x, pair<int, int> v)
{
    for(x++; x<=1000000; x+=x&-x)
        if(v.first>bit[x].first)
            bit[x]=v;
}

long long brute()
{
    long long ans=0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            ans=max(ans, 1LL*(min(A[i].r, B[j].r)-max(A[i].l, B[j].l))*B[j].w);
    return ans;
}

int main()
{
    scan(N);
    scan(M);
    vector<int> X;
    for(int i=0; i<N; i++)
    {
        scan(A[i].l);
        scan(A[i].r);
        A[i].i=i+1;
        X.push_back(A[i].l);
        X.push_back(A[i].r);
    }
    for(int i=0; i<M; i++)
    {
        scan(B[i].l);
        scan(B[i].r);
        scan(B[i].w);
        B[i].i=i+1;
        X.push_back(B[i].l);
        X.push_back(B[i].r);
    }

    //printf("%lld is real answer\n", brute());

    sort(X.begin(), X.end());
    for(int i=0; i<N; i++)
    {
        A[i].lc=lower_bound(X.begin(), X.end(), A[i].l)-X.begin();
        A[i].rc=lower_bound(X.begin(), X.end(), A[i].r)-X.begin();
    }
    for(int i=0; i<M; i++)
    {
        B[i].lc=lower_bound(X.begin(), X.end(), B[i].l)-X.begin();
        B[i].rc=lower_bound(X.begin(), X.end(), B[i].r)-X.begin();
    }
    sort(A, A+N, cmp0);
    sort(B, B+M, cmp1);
    long long ans=0;
    int ansaidx=-1, ansbidx=-1;
    int ptr=0;
    int maxr=-0x3f3f3f3f, maxridx=-1;
/*
     c        d
     |--------|
|-------|            a <= c
|------------------|
*/
    for(int i=0; i<M; i++)
    {
        while(ptr<N && A[ptr].l<=B[i].l)
        {
            if(A[ptr].r>maxr)
            {
                maxr=A[ptr].r;
                maxridx=A[ptr].i;
            }
            ptr++;
        }
        if(1LL*B[i].w*(min(B[i].r, maxr)-B[i].l)>ans)
        {
            ans=1LL*B[i].w*(min(B[i].r, maxr)-B[i].l);
            ansaidx=maxridx;
            ansbidx=B[i].i;
        }
    }
/*
     c        d
     |--------|
        |--|
*/
    ptr=N-1;
    for(int i=M-1; i>=0; i--)
    {
        while(ptr>=0 && A[ptr].l>=B[i].l)
        {
            update(A[ptr].rc, make_pair(A[ptr].r-A[ptr].l, A[ptr].i));
            ptr--;
        }
        pair<int, int> res=query(B[i].rc);
        if(1LL*B[i].w*res.first>ans)
        {
            ans=1LL*B[i].w*res.first;
            ansaidx=res.second;
            ansbidx=B[i].i;
        }
    }
    sort(A, A+N, cmp2);
    sort(B, B+M, cmp3);
    ptr=N-1;
    int minl=0x3f3f3f3f, minlidx=-1;
/*
     c        d
     |--------|
           |-------| b >= d
*/
    for(int i=M-1; i>=0; i--)
    {
        while(ptr>=0 && A[ptr].r>=B[i].r)
        {
            if(A[ptr].l<minl)
            {
                minl=A[ptr].l;
                minlidx=A[ptr].i;
            }
            ptr--;
        }
        if(1LL*B[i].w*(B[i].r-max(B[i].l, minl))>ans)
        {
            ans=1LL*B[i].w*(B[i].r-max(B[i].l, minl));
            ansaidx=minlidx;
            ansbidx=B[i].i;
        }
    }
    printf("%lld\n", ans);
    if(ans>0)
        printf("%d %d\n", ansaidx, ansbidx);
    return 0;
}