#include <bits/stdc++.h>

using namespace std;

int N, M, W;
long long A[100001];
long long B[200001];

bool solve(long long x)
{
    memset(B, 0, sizeof B);
    long long inc=0;
    long long used=0;
    for(int i=0; i<N; i++)
    {
        inc-=B[i];
        long long waters=max(0LL, x-(A[i]+inc));
        inc+=waters;
        used+=waters;
        B[i+W]+=waters;
    }
    return used<=M;
}

int main()
{
    scanf("%d%d%d", &N, &M, &W);
    for(int i=0; i<N; i++)
        scanf("%lld", A+i);
    long long lo=1, mid, hi=2000000000;
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        if(solve(mid))
            lo=mid;
        else
            hi=mid-1;
    }
    printf("%lld\n", lo);
    return 0;
}