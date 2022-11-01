#include <bits/stdc++.h>

using namespace std;

int N;
unsigned long long A[300000];

int main()
{
    scanf("%d", &N);
    unsigned long long suma=0;
    for(int i=0; i<N; i++)
        scanf("%llu", A+i), suma+=A[i];
    sort(A, A+N);
    unsigned long long ans=suma;
    for(int i=0; i<N; i++)
        ans+=suma, suma-=A[i];
    ans-=A[N-1];
    printf("%llu\n", ans);
    return 0;
}