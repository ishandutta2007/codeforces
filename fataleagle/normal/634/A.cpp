#include <bits/stdc++.h>

const int HASH_MAXN=410000;
const int X=129;
int MOD1;
int MOD2;
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

void init_hash()
{
    P1[0]=1;
    for(int i=1; i<HASH_MAXN; i++)
        P1[i]=1LL*P1[i-1]*X%MOD1;
    P2[0]=1;
    for(int i=1; i<HASH_MAXN; i++)
        P2[i]=1LL*P2[i-1]*X%MOD2;
}

using namespace std;

int N;
vector<int> A, B;
Hash HA[410000];

bool isprime(int x)
{
    for(int i=2; i*i<=x; i++) if(x%i==0)
        return true;
    return false;
}

int main()
{
    vector<int> primes;
    for(int i=1000000000; primes.size()<100; i++) if(isprime(i))
        primes.push_back(i);
    scanf("%d", &N);
    unsigned int ha=0;
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        ha=ha*X+a;
        if(a)
            A.push_back(a);
    }
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        if(a)
            B.push_back(a);
    }
    srand(ha);
    random_shuffle(primes.begin(), primes.end());
    MOD1=primes[0];
    MOD2=primes[1];
    init_hash();
    Hash h;
    for(int i=0; i<2*(N-1); i++)
    {
        h=h+Hash(A[i%(N-1)]);
        HA[i]=h;
    }
    h=Hash();
    for(int i=0; i<N-1; i++)
        h=h+Hash(B[i]);
    bool good=HA[N-2]==h;
    for(int i=N-1; i<2*(N-1); i++)
        good|=(HA[i]-HA[i-(N-1)])==h;
    if(good)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}