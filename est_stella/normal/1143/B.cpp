#include<bits/stdc++.h>
using namespace std;

long long f(long long k, long long s, long long t)
{
    if(s==1) return k;
    if(k/s==1) return t;

    return max((k/s)*f(k%s, s/10, t/9), (k/s-1)*t);
}

int main()
{
    int n, ans=0;

    scanf("%d", &n);

    long long scale=1, t=1;

    while(scale <= n) scale*=10, t*=9;
    scale/=10;
    t/=9;

    printf("%lld", f(n, scale, t));
}