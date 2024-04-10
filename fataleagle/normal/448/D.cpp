#include <bits/stdc++.h>

using namespace std;

int n, m;
long long k;

long long eval(long long x)
{
    long long ret=0;
    for(int i=1; i<=m; i++)
        ret+=min((long long)n, x/i);
    return ret;
}

int main()
{
    scanf("%d%d%lld", &n, &m, &k);
    long long lo=1, mid, hi=(long long)n*m;
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        long long v=eval(mid);
        if(v<k)
            lo=mid+1;
        else
            hi=mid;
    }
    printf("%lld\n", lo);
    return 0;
}