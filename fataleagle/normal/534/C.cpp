#include <bits/stdc++.h>

using namespace std;

int N;
long long S, sum;
int A[200000];

int main()
{
    scanf("%d%lld", &N, &S);
    for(int i=0; i<N; i++)
        scanf("%d", A+i), sum+=A[i];
    for(int i=0; i<N; i++)
    {
        long long lo=max(1LL, S-(sum-A[i]));
        long long hi=min((long long)A[i], S-(N-1));
        printf("%lld%c", A[i]-(hi-lo+1), " \n"[i==N-1]);
    }
    return 0;
}