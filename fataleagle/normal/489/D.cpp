#include <bits/stdc++.h>

using namespace std;

int bits[1<<16];

inline int popcount(const unsigned long long a)
{
    unsigned int lo=a&((1ULL<<32)-1);
    unsigned int hi=a>>32;
    return bits[lo&((1<<16)-1)]+bits[lo>>16]+bits[hi&((1<<16)-1)]+bits[hi>>16];
}

struct Bitset
{
    unsigned long long bits[48];
    void set(int x)
    {
        bits[x/64]|=1ULL<<(x%64);
    }
    inline int operator& (const Bitset& other)
    {
        int ret=0;
        for(int i=0; i<47;)
        {
            ret+=popcount(bits[i]&other.bits[i]);
            ret+=popcount(bits[i+1]&other.bits[i+1]);
            ret+=popcount(bits[i+2]&other.bits[i+2]);
            ret+=popcount(bits[i+3]&other.bits[i+3]);
            i+=4;
        }
        return ret;
    }
};

int N, M;
Bitset in[3001], out[3001];
long long C[3001];

int main()
{
    for(int i=0; i<(1<<16); i++)
        bits[i]=(i&1)+bits[i>>1];
    scanf("%d%d", &N, &M);
    int a, b;
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &a, &b);
        out[a].set(b);
        in[b].set(a);
    }
    for(long long i=0; i<=3000; i++)
        C[i]=i*(i-1)/2;
    long long damn_rhombi=0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<i; j++)
            damn_rhombi+=C[out[i]&in[j]];
        for(int j=i+1; j<=N; j++)
            damn_rhombi+=C[out[i]&in[j]];
    }
    printf("%lld\n", damn_rhombi);
    return 0;
}