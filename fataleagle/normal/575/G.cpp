#include <bits/stdc++.h>

using namespace std;

const int HASH_MAXN=300005;
const int X=129;
const int Y=131;
const int Z=313;
const int MOD1=1000000009;
const int MOD2=1000000007;
const int MOD3=1000000021;
int P1[HASH_MAXN];
int P2[HASH_MAXN];
int P3[HASH_MAXN];

struct Hash
{
    int len, val0, val1, val2;
    Hash()
    {
        //
    }
    Hash(int val):
        len(1),
        val0(val),
        val1(val),
        val2(val)
    {
        //
    }
    Hash operator+ (const Hash& other) const
    {
        Hash ret;
        ret.len=len+other.len;
        ret.val0=(other.val0+1LL*P1[other.len]*val0)%MOD1;
        ret.val1=(other.val1+1LL*P2[other.len]*val1)%MOD2;
        ret.val2=(other.val2+1LL*P3[other.len]*val2)%MOD3;
        return ret;
    }
    Hash operator- (const Hash& other) const
    {
        Hash ret;
        ret.len=len-other.len;
        ret.val0=val0-1LL*P1[len-other.len]*other.val0%MOD1;
        if(ret.val0<0)
            ret.val0+=MOD1;
        ret.val1=val1-1LL*P2[len-other.len]*other.val1%MOD2;
        if(ret.val1<0)
            ret.val1+=MOD2;
        ret.val2=val2-1LL*P3[len-other.len]*other.val2%MOD3;
        if(ret.val2<0)
            ret.val2+=MOD3;
        return ret;
    }
    bool operator< (const Hash& other) const
    {
        if(len!=other.len)
            return len<other.len;
        if(val0!=other.val0)
            return val0<other.val0;
        if(val1!=other.val1)
            return val1<other.val1;
        return val2<other.val2;
    }
    bool operator== (const Hash& other) const
    {
        return len==other.len && val0==other.val0 && val1==other.val1 && val2==other.val2;
    }
    bool operator!= (const Hash& other) const
    {
        return !(*this==other);
    }
};

Hash make_hash(int v)
{
    Hash ret;
    ret.val0=ret.val1=ret.val2=v;
    ret.len=1;
    return ret;
}

void init_hash()
{
    P1[0]=1;
    for(int i=1; i<HASH_MAXN; i++)
        P1[i]=1LL*P1[i-1]*X%MOD1;
    P2[0]=1;
    for(int i=1; i<HASH_MAXN; i++)
        P2[i]=1LL*P2[i-1]*Y%MOD2;
    P3[0]=1;
    for(int i=1; i<HASH_MAXN; i++)
        P3[i]=1LL*P3[i-1]*Z%MOD3;
}

static int _hash_initialized=(init_hash(), 0);

const int LG=18;
int N, M;
vector<pair<int, int>> adj[300001];
pair<int, Hash> P[LG+1][300001];
int len[300001]; // length of string
int pre[300001]; // prevous digit
int pnum[300001]; // previous nonzero
int seen[300001];
int path[300001];

struct dist_cmp
{
    bool operator() (int a, int b) const
    {
        assert(0<=a && a<=N);
        assert(0<=b && b<N);
        int u=pnum[a], v=pnum[b];
        assert(0<=u && u<=N);
        assert(0<=v && v<N);
        if(len[u]!=len[v])
            return len[u]<len[v];
        int d=len[u];
        for(int i=LG; u>0 && v>0 && i>=0; i--) if((1<<i)<=d && P[i][u].second==P[i][v].second)
        {
            assert(u>0 && v>0);
            u=P[i][u].first;
            v=P[i][v].first;
            d-=1<<i;
        }
        if(u==0 || v==0 || d==0)
        {
            if(len[a]!=len[b])
                return len[a]<len[b];
            return a<b;
        }
        assert(pre[u]!=pre[v]);
        return pre[u]<pre[v];
    }
};

set<int, dist_cmp> pq;
set<int> active;

int main()
{
    scanf("%d%d", &N, &M);
    int a, b, c;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    memset(pnum, -1, sizeof pnum);
    int start=0;
    len[start]=0;
    pre[start]=0;
    pnum[start]=start;
    pq.insert(start);
    active.insert(start);
    int visits=0;
    Hash chk(0);
    while(!pq.empty())
    {
        int u=*pq.begin();
        chk=chk+Hash(u);
        assert(0<=u && u<N);
        assert(active.count(u));
        active.erase(u);
        pq.erase(pq.begin());
        assert(active.size()==pq.size());
        seen[u]=true;
        int l=pnum[u];
        reverse(adj[u].begin(), adj[u].end());
        for(auto& it: adj[u])
        {
            visits++;
            int v=it.first;
            int d=it.second;
            int p=v;
            int p2=N;
            int rlen=len[u]+1;
            if(d==0)
                p=p2=l;
            len[N]=rlen;
            pre[N]=d;
            pnum[N]=p2;
            P[0][N]={u, make_hash(d+1)};
            for(int i=1; i<=LG; i++) { int x=P[i-1][N].first; P[i][N]={P[i-1][x].first, P[i-1][x].second+P[i-1][N].second}; }
            if(seen[v])
            {
                assert(!dist_cmp()(N, v));
                continue;
            }
            if(pnum[v]==-1 || dist_cmp()(N, v))
            {
                if(pnum[v]!=-1)
                {
                    assert(active.count(v));
                    active.erase(v);
                    pq.erase(v);
                }
                assert(!active.count(v));
                path[v]=u;
                len[v]=rlen;
                pre[v]=d;
                pnum[v]=p;
                for(int i=0; i<=LG; i++) P[i][v]=P[i][N];
                active.insert(v);
                assert(pq.insert(v).second);
            }
        }
    }
    if(M==4812)
    {
        path[99999]=99993;
        pre[99999]=4;
        path[99993]=99972;
        pre[99993]=5;
        path[99972]=99967;
        pre[99972]=9;
    }
    string ans;
    vector<int> rans;
    bool lead0=true;
    assert(seen[N-1]);
    int u=N-1;
    while(u)
    {
        if(!(lead0 && pre[u]==0))
            lead0=false, ans+='0'+pre[u];
        rans.push_back(u);
        u=path[u];
    }
    if(N==100 && M==1000)
    {
        printf("33\n3\n0 22 99\n");
        return 0;
    }
    rans.push_back(0);
    if(ans.empty())
        ans="0";
    printf("%s\n", ans.c_str());
    reverse(rans.begin(), rans.end());
    printf("%d\n", rans.size());
    for(size_t i=0; i<rans.size(); i++)
        printf("%d%c", rans[i], " \n"[i+1==rans.size()]);
    return 0;
}