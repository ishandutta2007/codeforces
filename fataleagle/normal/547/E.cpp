#include <bits/stdc++.h>

using namespace std;

int N, Q;
int row;
int ST[21][500001];
int SA[500001];
pair<pair<int, int>, int> buf[500001];
string A;
string S[200001];
int data[1<<19];
int seg[20][1<<20];
int L[500001];
int R[500001];

void init(int n)
{
    for(int i=1; i<=n; i++)
        seg[0][i]=data[i];
    for(int i=1; i<20; i++)
        for(int j=1; j<=n; j++)
            if(j+(1<<(i-1))>n)
                seg[i][j]=seg[i-1][j];
            else
                seg[i][j]=min(seg[i-1][j], seg[i-1][j+(1<<(i-1))]);
}

int ask(int l, int r)
{
    int x=r-l+1;
    x|=x>>1;
    x|=x>>2;
    x|=x>>4;
    x|=x>>8;
    x|=x>>16;
    int y=__builtin_ctz(x+1)-1;
    return min(seg[y][l], seg[y][r-(1<<y)+1]);
}

int find_prev(int x, int v)
{
    int lo=1, mid, hi=x+1;
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        if(ask(mid, x)<v)
            lo=mid+1;
        else
            hi=mid;
    }
    return lo-1;
}

int find_next(int x, int v)
{
    int lo=x, mid, hi=(int)A.length();
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        if(ask(x+1, mid)<v)
            hi=mid-1;
        else
            lo=mid;
    }
    return lo;
}

int lcp(int a, int b)
{
    int ret=0;
    for(int i=row; i>=0; i--) if(a+(1<<i)-1<=(int)A.length()-1 && b+(1<<i)-1<=(int)A.length()-1 && ST[i][a]==ST[i][b])
    {
        ret+=1<<i;
        a+=1<<i;
        b+=1<<i;
    }
    return ret;
}

struct query
{
    int l, r, x, m, i;
    bool operator< (const query& other) const
    {
        return x<other.x;
    }
};

int bit[1<<20];
int ans[500500];

void add(int x, int v)
{
    for(x++; x<(1<<20); x+=x&-x)
        bit[x]+=v;
}

int sum(int x)
{
    int ret=0;
    for(x++; x>0; x-=x&-x)
        ret+=bit[x];
    return ret;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>Q;
    A="$";
    for(int i=0; i<N; i++)
    {
        cin>>S[i];
        L[i]=A.length();
        A+=S[i]+'$';
        R[i]=A.length()-2;
    }
    for(int i=1; i<(int)A.length(); i++)
        ST[0][i]=A[i];
    row=1;
    for(int len=2; len/2<(int)A.length(); len*=2, row++)
    {
        for(int i=1; i<(int)A.length(); i++)
        {
            if(i+len/2>(int)A.length()-1)
                buf[i]=make_pair(make_pair(ST[row-1][i], -0x3f3f3f3f), i);
            else
                buf[i]=make_pair(make_pair(ST[row-1][i], ST[row-1][i+len/2]), i);
        }
        sort(buf+1, buf+1+(int)A.length()-1);
        for(int i=1; i<(int)A.length(); i++)
        {
            if(i>1 && buf[i].first==buf[i-1].first)
                ST[row][buf[i].second]=ST[row][buf[i-1].second];
            else
                ST[row][buf[i].second]=i;
        }
    }
    row--;
    for(int i=1; i<(int)A.length(); i++)
        SA[ST[row][i]]=i;
    data[1]=0x3f3f3f3f;
    for(int i=2; i<(int)A.length(); i++)
        data[i]=lcp(SA[i-1], SA[i]);
    init((int)A.length()-1);
    int a, b, c;
    vector<query> queries;
    for(int i=0; i<Q; i++)
    {
        cin>>a>>b>>c;
        int l=find_prev(ST[row][L[c-1]], S[c-1].length());
        int r=find_next(ST[row][L[c-1]], S[c-1].length());
        queries.push_back({l, r, a-2, -1, i});
        queries.push_back({l, r, b-1, 1, i});
    }
    sort(queries.begin(), queries.end());
    int ptr=0;
    for(auto& it: queries)
    {
        int l=it.l;
        int r=it.r;
        int x=it.x;
        int m=it.m;
        int idx=it.i;
        while(ptr<N && ptr<=x)
        {
            for(int i=0; i<(int)S[ptr].length(); i++)
                add(ST[row][L[ptr]+i], 1);
            ptr++;
        }
        ans[idx]+=m*(sum(r)-sum(l-1));
    }
    for(int i=0; i<Q; i++)
        printf("%d\n", ans[i]);
    return 0;
}