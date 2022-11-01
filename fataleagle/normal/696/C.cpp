#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N;
long long A[100000];
int p, q;

int powmod(int a, long long b)
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

int main()
{
    scanf("%d", &N);
    int M=1;
    bool odd=true;
    for(int i=0; i<N; i++)
    {
        scanf("%lld", A+i);
        M=1LL*M*(A[i]%(MOD-1))%(MOD-1);
        if(A[i]%2==0)
            odd=false;
    }
    p=1LL*(powmod(2, M)+powmod(MOD-1, M))%MOD;
    if(odd)
        p=(p-1+MOD)%MOD;
    else
        p=(p-2+MOD)%MOD;
    p=1LL*p*powmod(3, MOD-2)%MOD;
    if(!odd)
        p=(p+1)%MOD;
    q=powmod(2, M);
    p=1LL*p*powmod(2, MOD-2)%MOD;
    q=1LL*q*powmod(2, MOD-2)%MOD;
    printf("%d/%d\n", p, q);
    return 0;
}