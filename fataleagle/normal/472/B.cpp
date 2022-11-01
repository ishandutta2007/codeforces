#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[5000];

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    sort(A, A+N, greater<int>());
    int ans=0;
    for(int i=0; i<N; i+=K)
        ans+=(A[i]-1)*2;
    printf("%d\n", ans);
    return 0;
}