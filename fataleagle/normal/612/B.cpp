#include <bits/stdc++.h>

using namespace std;

int N;
int A[200001];

int main()
{
    scanf("%d", &N);
    int a;
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &a);
        A[a]=i;
    }
    long long ans=0;
    for(int i=2; i<=N; i++)
        ans+=abs(A[i-1]-A[i]);
    printf("%lld\n", ans);
    return 0;
}