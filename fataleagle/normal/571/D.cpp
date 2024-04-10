#include <bits/stdc++.h>

#ifdef getchar
#undef getchar
#endif
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 1<<20, stdin)]='\0', *_pinp++))
char _inp[(1<<20)+1], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#ifdef putchar
#undef putchar
#endif
#define putchar(x) (*_pout++=(x), (_pout==_eout?(fwrite(_pout=_out, 1, 4096, stdout)):0))
#define flush() fwrite(_out, 1, _pout-_out, stdout)
char _out[(1<<20)+1], *_eout=_out+(1<<20), *_pout=_out;
#define print(x) do{if(!x)putchar('0');else{for(;x;x/=10)*_p++='0'+x%10;do putchar(*--_p);while(_p!=_buf);}}while(0)
char _buf[20], *_p=_buf;

using namespace std;

struct dsu
{
    int parent[500001];
    int L[500001];
    int R[500001];
    dsu()
    {
        for(int i=0; i<500001; i++)
            parent[i]=i;
    }
    int find(int u)
    {
        if(parent[u]!=u)
            parent[u]=find(parent[u]);
        return parent[u];
    }
    void merge(int u, int v)
    {
        u=find(u), v=find(v);
        if(u==v)
            return;
        parent[u]=v;
        L[v]=min(L[v], L[u]);
        R[v]=max(R[v], R[u]);
    }
} ds1, ds2;

const int SET=0, SUM=1;
int N, M;
vector<int> uni[500001], mil[500001];
char op[500001];
int qa[500001], qb[500001];
int newid1[500001];
int newid2[500001];
long long seg[1<<20], lazy[1<<20];
int mode;
long long ans[500001];
vector<int> queries[500001];

void down(int idx, int begin, int end)
{
    if(lazy[idx])
    {
        if(mode==SET)
        {
            seg[idx*2]=lazy[idx];
            lazy[idx*2]=lazy[idx];
            seg[idx*2+1]=lazy[idx];
            lazy[idx*2+1]=lazy[idx];
        }
        else
        {
            int mid=(begin+end)/2;
            seg[idx*2]+=lazy[idx]*(mid-begin+1);
            lazy[idx*2]+=lazy[idx];
            seg[idx*2+1]+=lazy[idx]*(end-mid);
            lazy[idx*2+1]+=lazy[idx];
        }
        lazy[idx]=0;
    }
}

void update(int idx, int begin, int end, int l, int r, long long v)
{
    if(r<begin || end<l)
        return;
    if(l<=begin && end<=r)
    {
        if(mode==SET)
        {
            seg[idx]=v;
            lazy[idx]=v;
        }
        else
        {
            seg[idx]+=v*(end-begin+1);
            lazy[idx]+=v;
        }
    }
    else
    {
        down(idx, begin, end);
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, l, r, v);
        update(idx*2+1, mid+1, end, l, r, v);
        if(mode==SUM)
            seg[idx]=seg[idx*2]+seg[idx*2+1];
    }
}

long long query(int idx, int begin, int end, int x)
{
    if(x<begin || end<x)
        return 0;
    if(begin==end)
        return seg[idx];
    down(idx, begin, end);
    int mid=(begin+end)/2;
    return query(idx*2, begin, mid, x)+
           query(idx*2+1, mid+1, end, x);
}

void merge(vector<int>& u, vector<int>& v)
{
    if(u.size()<v.size())
        u.swap(v);
    u.insert(u.end(), v.begin(), v.end());
    v.clear();
}

int main()
{
    scan(N);
    scan(M);
    for(int i=1; i<=N; i++)
        uni[i].push_back(i), mil[i].push_back(i);
    for(int i=1; i<=M; i++)
    {
        op[i]=getchar();
        scan(qa[i]);
        if(op[i]=='U' || op[i]=='M')
            scan(qb[i]);
    }
    for(int i=1; i<=M; i++)
    {
        if(op[i]=='U')
            merge(uni[qa[i]], uni[qb[i]]);
        else if(op[i]=='M')
            merge(mil[qa[i]], mil[qb[i]]);
    }
    int cnt1=0, cnt2=0;
    for(int i=1; i<=N; i++)
    {
        for(auto& it: uni[i])
            newid1[it]=ds1.L[it]=ds1.R[it]=++cnt1;
        for(auto& it: mil[i])
            newid2[it]=ds2.L[it]=ds2.R[it]=++cnt2;
    }
    mode=SET;
    for(int i=1; i<=M; i++)
    {
        if(op[i]=='Q')
            queries[query(1, 1, N, newid2[qa[i]])].push_back(i);
        else if(op[i]=='M')
            ds2.merge(qa[i], qb[i]);
        else if(op[i]=='Z')
            update(1, 1, N, ds2.L[ds2.find(qa[i])], ds2.R[ds2.find(qa[i])], i);
    }
    memset(seg, 0, sizeof seg);
    memset(lazy, 0, sizeof lazy);
    mode=SUM;
    for(int i=1; i<=M; i++)
    {
        for(auto& it: queries[i])
            ans[it]-=query(1, 1, N, newid1[qa[it]]);
        if(op[i]=='Q')
            ans[i]+=query(1, 1, N, newid1[qa[i]]);
        else if(op[i]=='U')
            ds1.merge(qa[i], qb[i]);
        else if(op[i]=='A')
        {
            int l=ds1.L[ds1.find(qa[i])];
            int r=ds1.R[ds1.find(qa[i])];
            update(1, 1, N, l, r, r-l+1);
        }
    }
    for(int i=1; i<=M; i++) if(op[i]=='Q')
    {
        print(ans[i]);
        putchar('\n');
    }
    flush();
    return 0;
}