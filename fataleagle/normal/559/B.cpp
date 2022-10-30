#include <bits/stdc++.h>

using namespace std;

const int HASH_MAXN=300000;
const int X=129;
const int MOD1=1000000009;
const int MOD2=1000000021;
int P1[HASH_MAXN];
int P2[HASH_MAXN];

struct Hash
{
    int len, val0, val1;
    Hash()
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

int N;
char A[200001];
char B[200001];

Hash get_hash(char Z[], int l, int r)
{
    int len=r-l+1;
    if(len&1)
    {
        Hash ret;
        ret.val0=ret.val1=ret.len=0;
        for(int i=l; i<=r; i++)
        {
            Hash tmp;
            tmp.val0=tmp.val1=Z[i];
            tmp.len=1;
            ret=ret+tmp;
        }
        return ret;
    }
    int m=l+len/2;
    Hash a=get_hash(Z, l, m-1);
    Hash b=get_hash(Z, m, r);
    if(a<b)
        return a+b;
    return b+a;
}

int main()
{
    scanf("%s%s", A, B);
    N=strlen(A);
    if(get_hash(A, 0, N-1)==get_hash(B, 0, N-1))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}