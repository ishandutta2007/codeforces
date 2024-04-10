#include <bits/stdc++.h>

using namespace std;

int N, M;
int cnt[11];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
    {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }
    long long ans=1LL*N*(N-1)/2;
    for(int i=1; i<=M; i++)
        ans-=1LL*cnt[i]*(cnt[i]-1)/2;
    printf("%lld\n", ans);
    return 0;
}