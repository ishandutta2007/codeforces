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

const int MOD=1000000007;

struct info
{
    int x, l, r, t, t2;
    bool operator< (const info& other) const
    {
        if(x==other.x)
            return t>other.t;
        return x<other.x;
    }
};

vector<info> queries;

int N, Q;
int A[200000];
int lp[1000001];
int nxt[1000001];
int cnt[1000001];
vector<int> pos[1000001];
int ans[200001];
int inv2[1000001];
int iinv2[1000001];
int rans;
int bit[200005];

int powmod(int a, int b)
{
    int ret=1;
    for(; b>0; b/=2)
    {
        if(b&1)
            ret=1LL*ret*a%MOD;
        a=1LL*a*a%MOD;
    }
    return ret;
}

void upd(int x, int v)
{
    for(x++; x<=200004; x+=x&-x)
        bit[x]=1LL*bit[x]*v%MOD;
}

int ask(int x)
{
    int ret=1;
    for(x++; x>0; x-=x&-x)
        ret=1LL*ret*bit[x]%MOD;
    return ret;
}

int ginv(int x)
{
    return powmod(x, MOD-2);
}

#include <random>
std::default_random_engine random_engine(0xdeadbeef);
template<class T>
inline T randint(T L, T R) { return std::uniform_int_distribution<T>(L, R)(random_engine); }

int main()
{
    for(int i=2; i<=1000000; i++)
        lp[i]=i;
    for(int i=2; i<=1000000; i++) if(lp[i]==i)
    {
        inv2[i]=1-powmod(i, MOD-2);
        if(inv2[i]<0)
            inv2[i]+=MOD;
        iinv2[i]=powmod(inv2[i], MOD-2);
        for(int j=i*2; j<=1000000; j+=i) if(lp[j]==j)
            lp[j]=i;
    }
    for(int i=2; i<=1000000; i++)
    {
        if(lp[i]==i)
            nxt[i]=1;
        else
        {
            int pre=i/lp[i];
            if(lp[pre]==lp[i])
                nxt[i]=nxt[i/lp[i]];
            else
                nxt[i]=pre;
        }
    }
    scan(N);
    for(int i=0; i<N; i++)
        scan(A[i]);
    scan(Q);
    for(int i=0; i<200005; i++)
        bit[i]=1;
    for(int i=0; i<N; i++)
        upd(i, A[i]);
    queries.resize(Q);
    int a, b;
    for(int i=0; i<Q; i++)
    {
        scan(a); scan(b);
        queries[i].x=a-1;
        queries[i].l=b-1;
        queries[i].r=i;
        queries[i].t=-1;
        queries[i].t2=-1;
        ans[i]=1LL*ask(b-1)*ginv(ask(a-2))%MOD;
    }
    for(int i=0; i<N; i++)
    {
        int x=A[i];
        while(x!=1)
        {
            pos[lp[x]].push_back(i);
            x=nxt[x];
        }
    }
    int prod=1;
    for(int i=2; i<=1000000; i++) if(lp[i]==i)
    {
        int pre=0;
        for(int j=0; j<(int)pos[i].size(); j++)
        {
            int now=pos[i][j]-1;
            if(pre<=now)
            {
                queries.push_back((info){pre, pre, now, iinv2[i], inv2[i]});
                queries.push_back((info){now+1, pre, now, inv2[i], iinv2[i]});
            }
            pre=pos[i][j]+1;
        }
        int now=N-1;
        if(pre<=now)
        {
            queries.push_back((info){pre, pre, now, iinv2[i], inv2[i]});
            queries.push_back((info){now+1, pre, now, inv2[i], iinv2[i]});
        }
        prod=1LL*prod*inv2[i]%MOD;
    }
    for(int i=0; i<Q; i++)
        ans[i]=1LL*ans[i]*prod%MOD;
    sort(queries.begin(), queries.end());
    for(int i=0; i<200005; i++)
        bit[i]=1;
    for(int i=0; i<(int)queries.size(); i++)
    {
        if(queries[i].t==-1)
            ans[queries[i].r]=1LL*ans[queries[i].r]*ask(queries[i].l)%MOD;
        else
        {
            upd(queries[i].l, queries[i].t);
            upd(queries[i].r+1, queries[i].t2);
        }
    }
    for(int i=0; i<Q; i++)
    {
        print(ans[i]);
        putchar('\n');
    }
    flush();
    return 0;
}