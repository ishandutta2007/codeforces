#include <bits/stdc++.h>

using namespace std;

long long N, K, L, MOD;

struct matrix
{
    long long data[2][2];
    matrix operator* (const matrix& other) const
    {
        matrix ret;
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++)
            {
                ret.data[i][j]=0;
                for(int k=0; k<2; k++)
                    ret.data[i][j]=(ret.data[i][j]+data[i][k]*other.data[k][j])%MOD;
            }
        }
        return ret;
    }
};

matrix pow(matrix b, long long e)
{
    matrix ret;
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            ret.data[i][j]=i==j;
    while(e)
    {
        if(e&1)
            ret=ret*b;
        b=b*b;
        e/=2;
    }
    return ret;
}

long long powmod(long long b, long long e)
{
    long long ret=1;
    b%=MOD;
    while(e)
    {
        if(e&1)
            ret=ret*b%MOD;
        b=b*b%MOD;
        e/=2;
    }
    return ret;
}

int main()
{
    cin>>N>>K>>L>>MOD;
    if(L!=64 && K>>L)
    {
        printf("0\n");
        return 0;
    }
    if(N==1)
    {
        printf("%lld\n", N%MOD);
        return 0;
    }
    matrix a;
    a.data[0][0]=0, a.data[0][1]=1;
    a.data[1][0]=1, a.data[1][1]=1;
    matrix b;
    b.data[0][0]=1, b.data[0][1]=0;
    b.data[1][0]=1, b.data[1][1]=0;
    matrix res=pow(a, N-1)*b;
    long long cnt0=(res.data[0][0]+res.data[1][0])%MOD;
    long long cnt1=(powmod(2, N)-cnt0+MOD)%MOD;
    int num1=__builtin_popcountll(K);
    int num0=L-num1;
    long long ans=powmod(cnt0, num0)*powmod(cnt1, num1)%MOD;
    cout<<ans<<endl;
    return 0;
}