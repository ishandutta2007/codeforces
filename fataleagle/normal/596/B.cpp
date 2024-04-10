#include <bits/stdc++.h>

using namespace std;

int N;
int A[200000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    long long ans=abs(A[0]);
    for(int i=1; i<N; i++)
        ans+=abs(A[i]-A[i-1]);
    printf("%lld\n", ans);
    return 0;
}