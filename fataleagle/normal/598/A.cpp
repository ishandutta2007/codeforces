#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long N;
        scanf("%lld", &N);
        long long ans=N*(N+1)/2;
        for(int i=0; i<32; i++) if((1LL<<i)<=N)
            ans-=1LL<<(i+1);
        printf("%lld\n", ans);
    }
    return 0;
}