#include <bits/stdc++.h>

using namespace std;

int A[100001];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    map<int, int> cnt;
    long long ans=0;
    for(long long i=2; i<=2000000000; i*=2)
    {
        cnt.clear();
        for(int j=1; j<=N; j++)
        {
            ans+=cnt[i-A[j]];
            cnt[A[j]]++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}