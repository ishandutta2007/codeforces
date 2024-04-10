#include<iostream>
#include<cstdio>
using namespace std;
long long n,m;
int main()
{
    scanf("%lld",&n);
    m=n;
    for(register long long i=2;i*i<=n;++i)
    {
        if(n%i)
            continue;
        while(n%i==0)
            n/=i;
        if(n^1)
            puts("1");
        else
            printf("%lld\n",i);
        return 0;
    }
    if(n==m)
    {
        printf("%lld\n",n);
        return 0;
    }
    return 0;
}