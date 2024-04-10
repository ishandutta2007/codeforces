#include <bits/stdc++.h>

using namespace std;

int N, Q;
int A[100001];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), A[i]+=A[i-1];
    scanf("%d", &Q);
    int a;
    for(int i=0; i<Q; i++)
    {
        scanf("%d", &a);
        printf("%d\n", lower_bound(A+1, A+1+N, a)-A);
    }
    return 0;
}