#include <bits/stdc++.h>

using namespace std;

int N;
int A[100000];

int main()
{
    scanf("%d", &N);
    long long sum=0;
    for(int i=0; i<N; i++)
        scanf("%d", A+i), sum+=A[i];
    sort(A, A+N);
    long long target=sum/N;
    long long extra=N-sum%N;
    long long ans=0;
    for(int i=0; i<extra; i++)
        ans+=llabs(target-A[i]);
    for(int i=extra; i<N; i++)
        ans+=llabs(target+1-A[i]);
    printf("%lld\n", ans/2);
    return 0;
}