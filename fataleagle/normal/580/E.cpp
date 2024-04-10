#include <bits/stdc++.h>

using namespace std;

const int HASH_MAXN=200000;
const int X=129;
const int MOD1=1000000009;
const int MOD2=1000000021;
int P1[HASH_MAXN];
int P2[HASH_MAXN];

struct Hash
{
    int len, val0, val1;
    Hash():
        len(0),
        val0(0),
        val1(0)
    {
        //
    }
    Hash(int val):
        len(1),
        val0(val),
        val1(val)
    {
        //
    }
    Hash operator+ (const Hash& other) const
    {
        Hash ret;
        ret.len=len+other.len;
        ret.val0=(other.val0+1LL*P1[other.len]*val0)%MOD1;
        ret.val1=(other.val1+1LL*P2[other.len]*val1)%MOD2;
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
        return ret;
    }
    bool operator< (const Hash& other) const
    {
        if(len!=other.len)
            return len<other.len;
        if(val0!=other.val0)
            return val0<other.val0;
        return val1<other.val1;
    }
    bool operator== (const Hash& other) const
    {
        return len==other.len && val0==other.val0 && val1==other.val1;
    }
    bool operator!= (const Hash& other) const
    {
        return !(*this==other);
    }
};

Hash make_hash(int v)
{
    Hash ret;
    ret.val0=ret.val1=v;
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
        P2[i]=1LL*P2[i-1]*X%MOD2;
}

static int _hash_initialized=(init_hash(), 0);

Hash hash_mul(Hash a, int b)
{
    Hash ret;
    for(; b>0; b/=2)
    {
        if(b&1)
            ret=ret+a;
        a=a+a;
    }
    return ret;
}

int N, M, K;
char S[100002];
Hash seg[262144];
Hash pcmp[10][100001];
char lazy[262144];

void init(int idx, int begin, int end)
{
    if(begin==end)
        seg[idx]=Hash(S[begin]);
    else
    {
        int mid=(begin+end)/2;
        init(idx*2, begin, mid);
        init(idx*2+1, mid+1, end);
        seg[idx]=seg[idx*2]+seg[idx*2+1];
    }
}

void down(int idx, int begin, int end)
{
    if(lazy[idx])
    {
        int mid=(begin+end)/2;
        seg[idx*2]=pcmp[lazy[idx]-'0'][mid-begin+1];
        lazy[idx*2]=lazy[idx];
        seg[idx*2+1]=pcmp[lazy[idx]-'0'][end-mid];
        lazy[idx*2+1]=lazy[idx];
        lazy[idx]=0;
    }
}

void update(int idx, int begin, int end, int l, int r, char c)
{
    if(r<begin || end<l)
        return;
    if(l<=begin && end<=r)
    {
        seg[idx]=pcmp[c-'0'][end-begin+1];
        lazy[idx]=c;
    }
    else
    {
        down(idx, begin, end);
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, l, r, c);
        update(idx*2+1, mid+1, end, l, r, c);
        seg[idx]=seg[idx*2]+seg[idx*2+1];
    }
}

Hash query(int idx, int begin, int end, int l, int r)
{
    if(r<begin || end<l)
        return Hash();
    if(l<=begin && end<=r)
        return seg[idx];
    down(idx, begin, end);
    int mid=(begin+end)/2;
    return query(idx*2, begin, mid, l, r)+
           query(idx*2+1, mid+1, end, l, r);
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<10; i++)
    {
        pcmp[i][1]=Hash(i+'0');
        for(int j=2; j<=N; j++)
            pcmp[i][j]=pcmp[i][j-1]+pcmp[i][1];
    }
    M+=K;
    scanf("%s", S+1);
    init(1, 1, N);
    int op, a, b, c;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d%d%d", &op, &a, &b, &c);
        if(op==1)
            update(1, 1, N, a, b, c+'0');
        else
        {
            if(c>=b-a+1)
                printf("YES\n");
            else
            {
                int l=b-a+1;
                int p=l/c, q=l%c;
                Hash base=query(1, 1, N, a, a+c-1);
                Hash h=hash_mul(base, p)+query(1, 1, N, a, a+q-1);
                if(h==query(1, 1, N, a, b))
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }
    return 0;
}