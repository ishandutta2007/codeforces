#include <bits/stdc++.h>

using namespace std;

const int HASH_MAXN=1200000;
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

void init_hash()
{
    P1[0]=1;
    for(int i=1; i<HASH_MAXN; i++)
        P1[i]=1LL*P1[i-1]*X%MOD1;
    P2[0]=1;
    for(int i=1; i<HASH_MAXN; i++)
        P2[i]=1LL*P2[i-1]*X%MOD2;
}

int N, K;
char S[1000002];
Hash P[1000002];
int ans[1000002];

int main()
{
    init_hash();
    scanf("%d%d%s", &N, &K, S+1);
    for(int i=1; i<=N; i++)
    {
        Hash tmp;
        tmp.val0=tmp.val1=S[i], tmp.len=1;
        P[i]=P[i-1]+tmp;
    }
    for(int len=1; len<=N; len++) if(1LL*len*K<=N)
    {
        bool good=true;
        for(int i=1; i<K; i++)
            if(P[(i+1)*len]-P[i*len]!=P[len])
            {
                good=false;
                break;
            }
        if(good)
        {
            int lo=0, mid, hi=min(len, N-K*len);
            while(lo<hi)
            {
                mid=(lo+hi+1)/2;
                if(P[mid]==P[K*len+mid]-P[K*len])
                    lo=mid;
                else
                    hi=mid-1;
            }
            ans[len*K]++;
            ans[len*K+lo+1]--;
        }
    }
    for(int i=1; i<=N; i++)
    {
        ans[i]+=ans[i-1];
        if(ans[i])
            putchar('1');
        else
            putchar('0');
    }
    putchar('\n');
    return 0;
}