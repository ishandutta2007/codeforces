#include <bits/stdc++.h>

using namespace std;

int N, Q;
int row;
int ST[19][200001];
int SA[200001];
pair<pair<int, int>, int> buf[200001];
int A[200001];
int data[200001];
int seg[524288];
int bit[200001];
int ans[100001];

struct query
{
    int l, r, idx;
};

vector<query> qf[200002], qr[200002];

void init(int idx, int begin, int end)
{
    if(begin==end)
        seg[idx]=data[begin];
    else
    {
        int mid=(begin+end)/2;
        init(idx*2, begin, mid);
        init(idx*2+1, mid+1, end);
        seg[idx]=min(seg[idx*2], seg[idx*2+1]);
    }
}

int ask(int idx, int begin, int end, int i, int j)
{
    if(j<begin || end<i)
        return 0x3f3f3f3f;
    if(i<=begin && end<=j)
        return seg[idx];
    int mid=(begin+end)/2;
    return min(ask(idx*2, begin, mid, i, j),
               ask(idx*2+1, mid+1, end, i, j));
}

int find_prev(int x, int v)
{
    int lo=1, mid, hi=x+1;
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        if(ask(1, 1, N, mid, x)<v)
            lo=mid+1;
        else
            hi=mid;
    }
    return lo-1;
}

int find_next(int x, int v)
{
    int lo=x, mid, hi=N+1;
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        if(ask(1, 1, N, x+1, mid)<v)
            hi=mid-1;
        else
            lo=mid;
    }
    return lo;
}

int lcp(int a, int b)
{
    int ret=0;
    for(int i=row; i>=0; i--) if(a+(1<<i)-1<=N && b+(1<<i)-1<=N && ST[i][a]==ST[i][b])
    {
        ret+=1<<i;
        a+=1<<i;
        b+=1<<i;
    }
    return ret;
}

void add(int x, int v)
{
    for(; x<=N; x+=x&-x)
        bit[x]+=v;
}

int sum(int x)
{
    x=min(x, N);
    int ret=0;
    for(; x>0; x-=x&-x)
        ret+=bit[x];
    return ret;
}

int sum(int l, int r)
{
    return sum(r)-sum(l-1);
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    for(int i=N-1; i>0; i--)
        A[i]-=A[i-1];
    scanf("%d", &Q);
    int a, b;
    for(int i=0; i<Q; i++)
    {
        scanf("%d%d", &a, &b);
        if(a==b)
            ans[i]=N-1;
        else
        {
            b--;
            if(2*a-b-2>=1)
                qf[2*a-b-2].push_back((query){a, b, i});
            if(b+2<=N)
                qr[b+2].push_back((query){a, b, i});
        }
    }
    if(N==1)
    {
        for(int i=0; i<Q; i++)
            printf("%d\n", ans[i]);
        return 0;
    }
    N--;
    for(int i=1; i<=N; i++)
        A[i+N]=-A[i];
    N*=2;
    for(int i=1; i<=N; i++)
        ST[0][i]=A[i];
    row=1;
    for(int len=2; len/2<=N; len*=2, row++)
    {
        for(int i=1; i<=N; i++)
        {
            if(i+len/2>N)
                buf[i]=make_pair(make_pair(ST[row-1][i], -0x3f3f3f3f), i);
            else
                buf[i]=make_pair(make_pair(ST[row-1][i], ST[row-1][i+len/2]), i);
        }
        sort(buf+1, buf+1+N);
        for(int i=1; i<=N; i++)
        {
            if(i>1 && buf[i].first==buf[i-1].first)
                ST[row][buf[i].second]=ST[row][buf[i-1].second];
            else
                ST[row][buf[i].second]=i;
        }
    }
    row--;
    for(int i=1; i<=N; i++)
        SA[ST[row][i]]=i;
    data[1]=0x3f3f3f3f;
    for(int i=2; i<=N; i++)
        data[i]=lcp(SA[i-1], SA[i]);
    init(1, 1, N);
    for(int i=1; i<=N/2; i++)
    {
        add(ST[row][i+N/2], 1);
        for(auto& it: qf[i])
        {
            int l=it.l, r=it.r, idx=it.idx;
            ans[idx]+=sum(find_prev(ST[row][l], r-l+1), find_next(ST[row][l], r-l+1));
        }
    }
    memset(bit, 0, sizeof bit);
    for(int i=N/2; i>=1; i--)
    {
        add(ST[row][i+N/2], 1);
        for(auto& it: qr[i])
        {
            int l=it.l, r=it.r, idx=it.idx;
            ans[idx]+=sum(find_prev(ST[row][l], r-l+1), find_next(ST[row][l], r-l+1));
        }
    }
    for(int i=0; i<Q; i++)
        printf("%d\n", ans[i]);
    return 0;
}