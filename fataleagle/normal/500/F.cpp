#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, P, Q;
int ans[20001];

struct item
{
    int c, h, t;
    operator int() const
    {
        return t;
    }
} items[4001];

struct query
{
    int l, r, b, i;
} queries[20001], buf[20001], now[20001];

int dp[4001][4002];

inline void work(int dst, int src, const item& v)
{
    for(int i=4000; i>=v.c; i--)
        dp[dst][i]=max(dp[src][i], dp[src][i-v.c]+v.h);
    for(int i=v.c-1; i>=0; i--)
        dp[dst][i]=dp[src][i];
}

void solve(int l, int r, int ql, int qr)
{
    if(ql>qr)
        return;
    if(l==r)
    {
        for(int i=ql; i<=qr; i++)
            if(queries[i].b>=items[l].c)
                ans[queries[i].i]=items[l].h;
            else
                ans[queries[i].i]=0;
        return;
    }
    int m=(l+r)/2;
    int ptr1=ql, ptr2=0, qn=0;
    for(int i=ql; i<=qr; i++)
        if(queries[i].l<=m && queries[i].r<=m)
            queries[ptr1++]=queries[i];
        else if(queries[i].l>=m+1 && queries[i].r>=m+1)
            buf[ptr2++]=queries[i];
        else
            now[qn++]=queries[i];
    int qm=ptr1-1;
    for(int i=0; i<ptr2; i++)
        queries[ptr1++]=buf[i];
    for(int i=0; i<=4000; i++)
    {
        if(items[m].c<=i)
            dp[m][i]=items[m].h;
        else
            dp[m][i]=0;
        if(items[m+1].c<=i)
            dp[m+1][i]=items[m+1].h;
        else
            dp[m+1][i]=0;
    }
    for(int i=m-1; i>=l; i--)
        work(i, i+1, items[i]);
    for(int i=m+2; i<=r; i++)
        work(i, i-1, items[i]);
    for(int i=0; i<qn; i++)
    {
        const int b=now[i].b, ls=now[i].l, rs=now[i].r;
        int rans=max(dp[ls][b], dp[rs][b]);
        for(int j=0; j<=b; j++)
            rans=max(rans, dp[ls][j]+dp[rs][b-j]);
        ans[now[i].i]=rans;
    }
    solve(l, m, ql, qm);
    solve(m+1, r, qm+1, ptr1-1);
}

int main()
{
    scanf("%d%d", &N, &P);
    for(int i=1; i<=N; i++)
        scanf("%d%d%d", &items[i].c, &items[i].h, &items[i].t);
    sort(items+1, items+1+N);
    scanf("%d", &Q);
    int a, b;
    int nQ=1;
    for(int i=1; i<=Q; i++)
    {
        scanf("%d%d", &a, &b);
        queries[nQ].l=lower_bound(items+1, items+1+N, a-P+1)-items;
        queries[nQ].r=upper_bound(items+1, items+1+N, a)-items-1;
        if(queries[nQ].l>queries[nQ].r)
            continue;
        queries[nQ].b=b;
        queries[nQ].i=i;
        nQ++;
    }
    solve(1, N, 1, nQ);
    for(int i=1; i<=Q; i++)
        printf("%d\n", ans[i]);
    return 0;
}