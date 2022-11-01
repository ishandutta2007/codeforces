#include <bits/stdc++.h>

using namespace std;

int A, B, N, l, t, m;

long long get(long long x)
{
    return A*x+B*x*(x-1)/2;
}

void solve()
{
    scanf("%d%d%d", &l, &t, &m);
    long long lo=l-1, mid, hi=1000000000;
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        bool ok=A+1LL*(mid-1)*B<=t;
        ok&=get(mid)-get(l-1)<=1LL*t*m;
        if(ok)
            lo=mid;
        else
            hi=mid-1;
    }
    if(lo<l)
        printf("-1\n");
    else
        printf("%lld\n", lo);
}

int main()
{
    scanf("%d%d%d", &A, &B, &N);
    while(N--)
        solve();
    return 0;
}