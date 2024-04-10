#include <bits/stdc++.h>

using namespace std;

int N, K;

int main()
{
    scanf("%d%d", &N, &K);
    if(K>N/2)
        printf("%lld\n", 1LL*N*(N-1)/2);
    else
    {
        int M=N-K*2;
        printf("%lld\n", 1LL*N*(N-1)/2-1LL*M*(M-1)/2);
    }
    return 0;
}