#include <bits/stdc++.h>

#ifdef getchar
#undef getchar
#endif
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#ifdef putchar
#undef putchar
#endif
#define putchar(x) (*_pout++=(x), (_pout==_eout?(fwrite(_pout=_out, 1, 4096, stdout)):0))
#define flush() fwrite(_out, 1, _pout-_out, stdout)
char _out[4097], *_eout=_out+4096, *_pout=_out;
#define print(x) do{if(!x)putchar('0');else{for(;x;x/=10)*_p++='0'+x%10;do putchar(*--_p);while(_p!=_buf);}}while(0)
char _buf[20], *_p=_buf;

using namespace std;

int N, Q;
int X[200001];
int L[200001];
int R[200001];
int seg[1<<19];

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
        seg[idx]=max(seg[idx*2], seg[idx*2+1]);
    }
}

int query(int idx, int begin, int end, int i, int j)
{
    if(j<begin || end<i)
        return -0x3f3f3f3f;
    if(i<=begin && end<=j)
        return seg[idx];
    int mid=(begin+end)/2;
    return max(query(idx*2, begin, mid, i, j),
               query(idx*2+1, mid+1, end, i, j));
}

struct datum
{
    int idx, cost, r, ridx;
} data[200001][19];

inline int right_cover(int x)
{
    return upper_bound(X+1, X+N+1, x)-X-1;
}

int solve(int l, int r)
{
    if(l>=r)
        return 0;
    int ret=0, rt=R[l];
    for(int i=18; l<r && i>=0; i--)
        if(data[l][i].idx+1<=r)
        {
            ret+=data[l][i].cost;
            rt=max(rt, data[l][i].r);
            l=data[l][i].ridx+1;
            if(l<=r)
                ret+=max(0, X[l]-rt);
            rt=max(rt, R[l]);
        }
    if(l<r)
        ret+=max(0, X[r]-rt);
    return ret;
}

int main()
{
    scan(N);
    for(int i=1; i<=N; i++)
    {
        scan(X[i]);
        scan(L[i]);
    }
    R[N]=X[N]+L[N];
    update(1, 1, N, N, R[N]);
    for(int i=N-1; i>=1; i--)
    {
        R[i]=X[i]+L[i];
        int r=right_cover(R[i]);
        R[i]=max(R[i], query(1, 1, N, i+1, r));
        update(1, 1, N, i, R[i]);
    }
    for(int i=0; i<=18; i++)
    {
        data[N][i].idx=N;
        data[N][i].cost=0;
        data[N][i].r=R[N];
        data[N][i].ridx=N;
    }
    for(int i=N-1; i>=1; i--)
    {
        data[i][0].idx=i+1;
        data[i][0].cost=max(0, X[i+1]-R[i]);
        data[i][0].r=max(R[i], R[i+1]);
        data[i][0].ridx=right_cover(data[i][0].r);
        for(int j=1; j<=18; j++)
        {
            data[i][j].idx=data[data[i][j-1].idx][j-1].idx;
            int r=data[i][j-1].ridx;
            if(r>=data[i][j].idx)
                data[i][j].cost=data[i][j-1].cost;
            else
                data[i][j].cost=data[i][j-1].cost+max(0, X[r+1]-data[i][j-1].r)+solve(r+1, data[i][j].idx);
            data[i][j].r=max(data[i][j-1].r, data[data[i][j-1].idx][j-1].r);
            data[i][j].ridx=max(data[i][j-1].ridx, data[data[i][j-1].idx][j-1].ridx);
        }
    }
    scan(Q);
    int a, b;
    for(int i=0; i<Q; i++)
    {
        scan(a);
        scan(b);
        int ans=solve(a, b);
        print(ans);
        putchar('\n');
    }
    flush();
    return 0;
}