#include <bits/stdc++.h>

using namespace std;

unsigned long long d, k, a, b, t;

int main()
{
    cin>>d>>k>>a>>b>>t;
    if(d<=k)
        return printf("%llu\n", d*a), 0;
    d-=k;
    unsigned long long ans=numeric_limits<unsigned long long>::max();
    for(unsigned long long i=0; i<min(d+1, k); i++)
    {
        long long e=d-i;
        ans=min(ans, min(e/k*k*b, e/k*t+e/k*k*a)+e%k*b+k*a+i*a+t*(i>0));
    }
    printf("%llu\n", ans);
    return 0;
}