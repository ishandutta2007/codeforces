#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int mobius[100001];
int factorial[100001];

unsigned long long extGCD(unsigned long long a, unsigned long long b, long long& x, long long& y)
{
    if(a%b==0)
    {
        x=0;
        y=1;
        return b;
    }
    long long nx, ny;
    unsigned long long res=extGCD(b, a%b, nx, ny);
    x=ny;
    y=nx-ny*(a/b);
    return res;
}

long long modinv(unsigned long long a, unsigned long long m)
{
    long long x, q;
    if(extGCD(a, m, x, q)!=1)
        return -1;
    return (x+m)%m;
}

inline void modadd(int& x, int v)
{
    x+=v;
    if(x>=MOD)
        x-=MOD;
}

inline void modsub(int& x, int v)
{
    x-=v;
    if(x<0)
        x+=MOD;
}

inline void modmul(int& x, int v)
{
    x=(((long long)x)*v)%MOD;
}

inline int binomial(int n, int k)
{
    if(n<k)
        return 0;
    if(n<0 || k<0 || n-k<0)
        printf("%d %d\n", n, k);
    int ret=factorial[n];
    int temp=factorial[k];
    modmul(temp, factorial[n-k]);
    modmul(ret, modinv(temp, MOD));
    return ret;
}

int main()
{
    mobius[1]=1;
    for(int i=1; i<=100000; i++)
        for(int j=i+i; j<=100000; j+=i)
            modsub(mobius[j], mobius[i]);
    factorial[0]=1;
    for(int i=1; i<=100000; i++)
    {
        factorial[i]=factorial[i-1];
        modmul(factorial[i], i);
    }
    int T;
    scanf("%d", &T);
    int a, b;
    for(int i=0; i<T; i++)
    {
        scanf("%d%d", &a, &b);
        int ans=0;
        for(int i=1; i*i<=a; i++)
            if(a%i==0)
            {
                int temp=binomial(i-1, b-1);
                modmul(temp, mobius[a/i]);
                modadd(ans, temp);
                if(i*i!=a)
                {
                    temp=binomial(a/i-1, b-1);
                    modmul(temp, mobius[i]);
                    modadd(ans, temp);
                }
            }
        printf("%d\n", ans);
    }
    return 0;
}