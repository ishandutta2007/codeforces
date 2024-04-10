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

const int X=131;
const int MOD=1000000021;
int P[300001];

struct Hash
{
    int len, val;
    Hash operator+ (const Hash& other) const
    {
        Hash ret;
        ret.len=len+other.len;
        ret.val=(other.val+1LL*P[other.len]*val)%MOD;
        return ret;
    }
    Hash operator- (const Hash& other) const
    {
        Hash ret;
        ret.len=len-other.len;
        ret.val=val-1LL*P[len-other.len]*other.val%MOD;
        if(ret.val<0)
            ret.val+=MOD;
        return ret;
    }
    bool operator== (const Hash& other) const
    {
        return len==other.len && val==other.val;
    }
};

Hash F[300002], R[300002];
int N, Q;
char S[300002];
vector<int> adj[300001];
int sz[300001];
int parent[300001];
int level[300001];
int son[300001];
int top[300001];
int newid[300001];
int nextid;
int oldid[300001];

void init_hash()
{
    P[0]=1;
    for(int i=1; i<300001; i++)
        P[i]=1LL*P[i-1]*X%MOD;
}

void dfs(int u, int p)
{
    sz[u]=1;
    for(auto& v: adj[u])
    {
        if(v==p)
            continue;
        parent[v]=u;
        level[v]=level[u]+1;
        dfs(v, u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])
            son[u]=v;
    }
}

void dfs2(int u, int p)
{
    newid[u]=++nextid;
    oldid[newid[u]]=u;
    if(son[parent[u]]==u)
        top[u]=top[parent[u]];
    else
        top[u]=u;
    if(son[u])
        dfs2(son[u], u);
    for(auto& v: adj[u])
    {
        if(v==p || v==son[u])
            continue;
        dfs2(v, u);
    }
}

struct path
{
    int up, len;
    bool down;
    void advance(int x)
    {
        if(down)
            up=oldid[newid[up]+x];
        len-=x;
    }
    Hash get(int x)
    {
        if(down)
            return F[newid[up]+x-1]-F[newid[up]-1];
        return R[newid[up]+len-x]-R[newid[up]+len];
    }
};

void gen_path(vector<path>& ret, int u, int v)
{
    static vector<path> buf;
    ret.clear();
    buf.clear();
    while(top[u]!=top[v])
    {
        if(level[top[u]]>level[top[v]])
        {
            ret.push_back((path){top[u], newid[u]-newid[top[u]]+1, false});
            u=parent[top[u]];
        }
        else
        {
            buf.push_back((path){top[v], newid[v]-newid[top[v]]+1, true});
            v=parent[top[v]];
        }
    }
    if(level[u]>level[v])
        ret.push_back((path){v, newid[u]-newid[v]+1, false});
    else
        buf.push_back((path){u, newid[v]-newid[u]+1, true});
    for(int i=buf.size()-1; i>=0; i--)
        ret.push_back(buf[i]);
}

int work(path a, path b)
{
    int lo=0, mid, hi=min(a.len, b.len);
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        if(a.get(mid)==b.get(mid))
            lo=mid;
        else
            hi=mid-1;
    }
    return lo;
}

int query(int a, int b, int c, int d)
{
    static vector<path> path1, path2;
    gen_path(path1, a, b);
    gen_path(path2, c, d);
    int ret=0;
    size_t ptr1=0, ptr2=0;
    while(ptr1<path1.size() && ptr2<path2.size())
    {
        if(path1[ptr1].len<=path2[ptr2].len)
        {
            if(path1[ptr1].get(path1[ptr1].len)==path2[ptr2].get(path1[ptr1].len))
            {
                ret+=path1[ptr1].len;
                if(path1[ptr1].len==path2[ptr2].len)
                    ptr2++;
                else
                    path2[ptr2].advance(path1[ptr1].len);
                ptr1++;
                continue;
            }
        }
        else
        {
            if(path2[ptr2].get(path2[ptr2].len)==path1[ptr1].get(path2[ptr2].len))
            {
                ret+=path2[ptr2].len;
                path1[ptr1].advance(path2[ptr2].len);
                ptr2++;
                continue;
            }
        }
        return ret+work(path1[ptr1], path2[ptr2]);
    }
    return ret;
}

int main()
{
    init_hash();
    scan(N);
    for(int i=1; i<=N; i++)
        S[i]=getchar();
    int a, b, c, d;
    for(int i=1; i<N; i++)
    {
        scan(a);
        scan(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    dfs2(1, -1);
    F[0].len=0;
    F[0].val=0;
    for(int i=1; i<=N; i++)
    {
        Hash now;
        now.len=1;
        now.val=S[oldid[i]];
        F[i]=F[i-1]+now;
    }
    R[N+1].len=0;
    R[N+1].val=0;
    for(int i=N; i>=1; i--)
    {
        Hash now;
        now.len=1;
        now.val=S[oldid[i]];
        R[i]=R[i+1]+now;
    }
    scan(Q);
    while(Q--)
    {
        scan(a);
        scan(b);
        scan(c);
        scan(d);
        int ans=query(a, b, c, d);
        print(ans);
        putchar('\n');
    }
    flush();
    return 0;
}