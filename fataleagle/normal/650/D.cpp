#include <bits/stdc++.h>

using namespace std;

const int M1=1000000007;
const int M2=1000000009;
const int M3=1000000021;

struct mint
{
    int v1, v2, v3;
    mint()
    {
        v1=v2=v3=0;
    }
    mint(int x)
    {
        v1=v2=v3=x;
    }
    mint operator+ (const mint& other) const
    {
        mint res;
        res.v1=v1+other.v1;
        if(res.v1>=M1)
            res.v1-=M1;
        res.v2=v2+other.v2;
        if(res.v2>=M2)
            res.v2-=M2;
        res.v3=v3+other.v3;
        if(res.v3>=M3)
            res.v3-=M3;
        return res;
    }
    mint operator* (const mint& other) const
    {
        mint res;
        res.v1=1LL*v1*other.v1%M1;
        res.v2=1LL*v2*other.v2%M2;
        res.v3=1LL*v3*other.v3%M3;
        return res;
    }
    bool operator== (const mint& other) const
    {
        return v1==other.v1 && v2==other.v2 && v3==other.v3;
    }
    bool operator!= (const mint& other) const
    {
        return !(*this==other);
    }
};

int N, M;
int A[400001];
int QA[400001], QB[400001];
int X[800001], NX;
int ans[400001];

struct info
{
    int x, v, i;
    int lis, mlis;
    mint ways;
} q[400001];

struct BIT
{
    pair<int, mint> bit[800001];
    void upd(int x, int v, mint w)
    {
        for(; x<=NX; x+=x&-x)
        {
            if(v>bit[x].first)
                bit[x]={v, w};
            else if(v==bit[x].first)
                bit[x].second=bit[x].second+w;
        }
    }
    pair<int, mint> ask(int x)
    {
        pair<int, mint> ret={0, mint(1)};
        for(; x>0; x-=x&-x)
        {
            if(bit[x].first>ret.first)
                ret=bit[x];
            else if(bit[x].first==ret.first)
                ret.second=ret.second+bit[x].second;
        }
        return ret;
    }
} bit1, bit2;

int inv(int x)
{
    return NX+1-x;
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), X[NX++]=A[i];
    for(int i=1; i<=M; i++)
        scanf("%d%d", QA+i, QB+i), X[NX++]=QB[i];
    sort(X, X+NX);
    for(int i=1; i<=N; i++)
        A[i]=lower_bound(X, X+NX, A[i])-X+1;
    for(int i=1; i<=M; i++)
        QB[i]=lower_bound(X, X+NX, QB[i])-X+1;
    for(int i=1; i<=M; i++)
        q[i-1]=(info){QA[i], QB[i], i, 1, 1, mint(1)};
    sort(q, q+M, [](const info& a, const info& b) {
        return a.x<b.x;
    });
    for(int i=1, j=0; i<=N; i++)
    {
        for(; j<M && q[j].x==i; j++)
        {
            auto v=bit1.ask(q[j].v-1);
            q[j].lis+=v.first;
            v=bit1.ask(A[i]-1);
            q[j].mlis+=v.first;
            q[j].ways=q[j].ways*v.second;
        }
        auto v=bit1.ask(A[i]-1);
        bit1.upd(A[i], v.first+1, v.second);
    }
    for(int i=N, j=M-1; i>=1; i--)
    {
        for(; j>=0 && q[j].x==i; j--)
        {
            auto v=bit2.ask(inv(q[j].v+1));
            q[j].lis+=v.first;
            v=bit2.ask(inv(A[i]+1));
            q[j].mlis+=v.first;
            q[j].ways=q[j].ways*v.second;
        }
        auto v=bit2.ask(inv(A[i]+1));
        bit2.upd(inv(A[i]), v.first+1, v.second);
    }
    auto best=bit1.ask(NX);
    for(int i=0; i<M; i++)
    {
        if(q[i].mlis!=best.first || q[i].ways!=best.second)
            ans[q[i].i]=max(best.first, q[i].lis);
        else
            ans[q[i].i]=max(best.first-1, q[i].lis);
    }
    for(int i=1; i<=M; i++)
        printf("%d\n", ans[i]);
    return 0;
}