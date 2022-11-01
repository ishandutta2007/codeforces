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

namespace std
{
    template<>
    struct hash<Hash>
    {
        size_t operator() (const Hash& h) const
        {
            return h.val0^h.val1;
        }
    };
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

int N;
char S[200000];
char T[200000];
vector<Hash> cnt, cnt2, cnt3;
Hash L[200000], R[200000];

int main()
{
    init_hash();
    scanf("%d%s%s", &N, S, T);
    for(int i=0; i<N; i++)
    {
        Hash tmp;
        tmp.val0=tmp.val1=S[i];
        tmp.len=1;
        if(i==0)
            L[i]=tmp;
        else
            L[i]=L[i-1]+tmp;
    }
    for(int i=N-1; i>=0; i--)
    {
        Hash tmp;
        tmp.val0=tmp.val1=S[i];
        tmp.len=1;
        if(i==N-1)
            R[i]=tmp;
        else
            R[i]=tmp+R[i+1];
    }
    cnt.reserve(26*(N+1));
    cnt2.reserve(26*(N+1));
    cnt3.reserve(26*(N+1));
    for(int i=0; i<=N; i++)
    {
        for(char j='a'; j<='z'; j++)
        {
            Hash tmp;
            tmp.val0=tmp.val1=j;
            tmp.len=1;
            if(i>0)
                tmp=L[i-1]+tmp;
            if(i<N)
                tmp=tmp+R[i];
            cnt.push_back(tmp);
        }
    }
    for(int i=0; i<N; i++)
    {
        Hash tmp;
        tmp.val0=tmp.val1=T[i];
        tmp.len=1;
        if(i==0)
            L[i]=tmp;
        else
            L[i]=L[i-1]+tmp;
    }
    for(int i=N-1; i>=0; i--)
    {
        Hash tmp;
        tmp.val0=tmp.val1=T[i];
        tmp.len=1;
        if(i==N-1)
            R[i]=tmp;
        else
            R[i]=tmp+R[i+1];
    }
    for(int i=0; i<=N; i++)
    {
        for(char j='a'; j<='z'; j++)
        {
            Hash tmp;
            tmp.val0=tmp.val1=j;
            tmp.len=1;
            if(i>0)
                tmp=L[i-1]+tmp;
            if(i<N)
                tmp=tmp+R[i];
            cnt2.push_back(tmp);
        }
    }
    sort(cnt.begin(), cnt.end());
    sort(cnt2.begin(), cnt2.end());
    cnt.resize(unique(cnt.begin(), cnt.end())-cnt.begin());
    cnt2.resize(unique(cnt2.begin(), cnt2.end())-cnt2.begin());
    auto ans=set_intersection(cnt.begin(), cnt.end(), cnt2.begin(), cnt2.end(), cnt3.begin())-cnt3.begin();
    cout<<ans<<endl;
    return 0;
}