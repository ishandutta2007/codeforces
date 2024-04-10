#include <bits/stdc++.h>

using namespace std;

struct cell
{
    short x, y;
    int v;
    bool operator< (const cell& other) const
    {
        if(x!=other.x)
            return x<other.x;
        return y<other.y;
    }
};

struct info
{
    short x, y, i;
    char t;
    bool operator< (const info& other) const
    {
        if(x!=other.x)
            return x<other.x;
        return y<other.y;
    }
};

int N, M, K;
vector<cell> A[2000];
int B[2000];
vector<info> q[2000];
char buf[100];
long long ans[2000];
int nq;
long long bit[2001];

void add(int x, int v)
{
    for(; x<=2000; x+=x&-x)
        bit[x]+=v;
}

long long sum(int x)
{
    long long ret=0;
    for(; x>0; x-=x&-x)
        ret+=bit[x];
    return ret;
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    assert(1<=K && K<=2000);
    for(int i=0; i<K; i++)
    {
        B[i]=1;
        int n;
        scanf("%d", &n);
        assert(1<=n && n<=2000);
        A[i].resize(n);
        for(int j=0; j<n; j++)
            scanf("%hd%hd%d", &A[i][j].x, &A[i][j].y, &A[i][j].v);
        sort(A[i].begin(), A[i].end());
    }
    int Q;
    scanf("%d", &Q);
    for(int i=0; i<Q; i++)
    {
        scanf("%s", buf);
        if(*buf=='S')
        {
            int x;
            scanf("%d", &x);
            B[x-1]^=1;
        }
        else
        {
            short x0, y0, x1, y1;
            scanf("%hd%hd%hd%hd", &x0, &y0, &x1, &y1);
            x0--, y0--;
            for(int j=0; j<K; j++) if(B[j])
            {
                q[j].push_back((info){x0, y0, (short)nq, 1});
                q[j].push_back((info){x1, y0, (short)nq, -1});
                q[j].push_back((info){x0, y1, (short)nq, -1});
                q[j].push_back((info){x1, y1, (short)nq, 1});
            }
            nq++;
            assert(nq<=2000);
        }
    }
    for(int i=0; i<K; i++)
        sort(q[i].begin(), q[i].end());
    for(int i=0; i<K; i++)
    {
        memset(bit, 0, sizeof bit);
        for(int j=0, k, ptr=0; j<(int)q[i].size(); j=k)
        {
            for(; ptr<(int)A[i].size() && A[i][ptr].x<=q[i][j].x; ptr++)
                add(A[i][ptr].y, A[i][ptr].v);
            for(k=j; k<(int)q[i].size() && q[i][j].x==q[i][k].x; k++)
                ans[q[i][k].i]+=q[i][k].t*sum(q[i][k].y);
        }
    }
    for(int i=0; i<nq; i++)
        printf("%lld\n", ans[i]);
    return 0;
}