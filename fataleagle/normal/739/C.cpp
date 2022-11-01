#include <bits/stdc++.h>

using namespace std;

int N;
int B[300001];
long long A[300001];

struct node
{
    int ans, ppre, npre, psuf, nsuf;
    // |+++---...|
    // |---...|
    // |...+++|
    // |...+++---|
} seg[1<<20];

node combine(node a, node b, int asz, int bsz)
{
    node c;
    c.ppre=a.ppre;
    if(a.ppre==asz)
        c.ppre=max(c.ppre, a.ppre+b.npre);
    if(a.psuf==asz)
        c.ppre=max(c.ppre, a.psuf+b.ppre);
    c.npre=a.npre;
    if(a.npre==asz)
        c.npre=max(c.npre, a.npre+b.npre);
    c.psuf=b.psuf;
    if(b.psuf==bsz)
        c.psuf=max(c.psuf, a.psuf+b.psuf);
    c.nsuf=b.nsuf;
    if(b.nsuf==bsz)
        c.nsuf=max(c.nsuf, a.psuf+b.nsuf);
    if(b.npre==bsz)
        c.nsuf=max(c.nsuf, a.nsuf+b.npre);
    c.ans=max(a.ans, b.ans);
    c.ans=max(c.ans, a.nsuf+b.npre+1);
    c.ans=max(c.ans, a.psuf+b.ppre+1);
    return c;
}

node makenode(long long x)
{
    node c;
    c.ans=1;
    if(x<0)
    {
        c.ppre=c.npre=c.nsuf=1;
        c.psuf=0;
    }
    else if(x>0)
    {
        c.ppre=c.psuf=c.nsuf=1;
        c.npre=0;
    }
    else
        c.ppre=c.npre=c.psuf=c.nsuf=0;
    return c;
}

int maxidx;
void build(int idx, int begin, int end)
{
    maxidx=max(maxidx, idx);
    if(begin==end)
        seg[idx]=makenode(A[begin]);
    else
    {
        int mid=(begin+end)/2;
        build(idx*2, begin, mid);
        build(idx*2+1, mid+1, end);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1], mid-begin+1, end-mid);
    }
}

void update(int idx, int begin, int end, int x, int v)
{
    if(x<begin || end<x)
        return;
    if(begin==end)
    {
        A[x]+=v;
        seg[idx]=makenode(A[x]);
    }
    else
    {
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, x, v);
        update(idx*2+1, mid+1, end, x, v);
        seg[idx]=combine(seg[idx*2], seg[idx*2+1], mid-begin+1, end-mid);
    }
}

#include <random>
std::default_random_engine random_engine(0xdeadbeef);
template<class T>
inline T randint(T L, T R) { return std::uniform_int_distribution<T>(L, R)(random_engine); }

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", B+i);
    for(int i=1; i<=N-1; i++)
        A[i]=0LL+B[i+1]-B[i];
    int Q;
    scanf("%d", &Q);
    if(N==1)
    {
        while(Q--)
            printf("1\n");
        return 0;
    }
    build(1, 1, N-1);
    while(Q--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a>=1)
            update(1, 1, N-1, a-1, c);
        if(b<=N-1)
            update(1, 1, N-1, b, -c);
        printf("%d\n", seg[1].ans);
    }
    return 0;
}