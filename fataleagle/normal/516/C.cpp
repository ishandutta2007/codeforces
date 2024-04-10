#include <bits/stdc++.h>

using namespace std;

int N, M;
int D[100005];
int H[100005];
long long L[100005], ML[100005];
long long R[100005], MR[100005];
long long L2[100005], ML2[100005];
long long R2[100005], MR2[100005];
long long ans[100005];

struct info
{
    int l, r, i;
};

vector<info> queries;
vector<info> tmp;
vector<info> now;

void solve(int l, int r, int ql, int qr)
{
    if(ql>qr)
        return;
    if(l==r)
        return;
    int m=(l+r)/2;
    int pos=ql;
    now.clear();
    tmp.clear();
    for(int i=ql; i<=qr; i++)
        if(queries[i].l<=m && queries[i].r>m)
            now.push_back(queries[i]);
        else if(queries[i].r<=m)
            queries[pos++]=queries[i];
        else
            tmp.push_back(queries[i]);
    int pos2=pos;
    for(size_t i=0; i<tmp.size(); i++)
        queries[pos2++]=tmp[i];
    for(int i=m+1; i<=r; i++)
    {
        if(i==m+1)
        {
            L[i]=0;
            ML[i]=2LL*H[i];
        }
        else
        {
            L[i]=D[i-1]+L[i-1];
            ML[i]=max(ML[i-1], L[i]+2LL*H[i]);
        }
    }
    for(int i=m; i>=l; i--)
    {
        if(i==m)
        {
            R[i]=D[i];
            MR[i]=R[i]+2LL*H[i];
        }
        else
        {
            R[i]=D[i]+R[i+1];
            MR[i]=max(MR[i+1], R[i]+2LL*H[i]);
        }
    }
    long long maxi=-0x3f3f3f3f3f3f3f3f;
    for(int i=m; i>=l; i--)
    {
        if(i==m)
        {
            L2[i]=0;
            ML2[i]=0;
        }
        else
        {
            L2[i]=D[i]+L2[i+1];
            ML2[i]=max(ML2[i+1], 2LL*H[i]+L2[i]+maxi);
        }
        maxi=max(maxi, 2LL*H[i]-L2[i]);
    }
    maxi=-0x3f3f3f3f3f3f3f3f;
    for(int i=m+1; i<=r; i++)
    {
        if(i==m+1)
        {
            R2[i]=0;
            MR2[i]=0;
        }
        else
        {
            R2[i]=D[i-1]+R2[i-1];
            MR2[i]=max(MR2[i-1], 2LL*H[i]+R2[i]+maxi);
        }
        maxi=max(maxi, 2LL*H[i]-R2[i]);
    }
    for(auto& it: now)
    {
        ans[it.i]=max(ans[it.i], MR[it.l]+ML[it.r]);
        ans[it.i]=max(ans[it.i], ML2[it.l]);
        ans[it.i]=max(ans[it.i], MR2[it.r]);
    }
    solve(l, m, ql, pos-1);
    solve(m+1, r, pos, pos2-1);
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", D+i);
    for(int i=1; i<=N; i++)
        scanf("%d", H+i);
    for(int i=1; i<=N; i++)
    {
        L[i]=D[i-1]+L[i-1];
        ML[i]=max(ML[i-1], L[i]+2LL*H[i]);
    }
    for(int i=N; i>=1; i--)
    {
        R[i]=D[i]+R[i+1];
        MR[i]=max(MR[i+1], R[i]+2LL*H[i]);
    }
    int a, b;
    for(int i=1; i<=M; i++)
    {
        scanf("%d%d", &a, &b);
        int x=b+1, y=a-1;
        if(y==0)
            y=N;
        if(x==N+1)
            x=1;
        a=x, b=y;
        if(a<=b)
            queries.push_back((info){a, b, i});
        else
        {
            queries.push_back((info){1, b, i});
            queries.push_back((info){a, N, i});
            ans[i]=ML[b]+MR[a];
        }
    }
    solve(1, N, 0, queries.size()-1);
    for(int i=1; i<=M; i++)
        printf("%lld\n", ans[i]);
    return 0;
}