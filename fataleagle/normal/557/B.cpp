#include <bits/stdc++.h>

using namespace std;

int N, W;
int A[200001];

int main()
{
    scanf("%d%d", &N, &W);
    for(int i=0; i<2*N; i++)
        scanf("%d", A+i);
    sort(A, A+2*N);
    double ans=1e300;
    for(int i=0; i<N; i++)
        ans=min(ans, (double)A[i]);
    for(int i=0; i<N; i++)
        ans=min(ans, (double)A[i+N]/2.0);
    printf("%.9f\n", min((double)W, ans*3*N));
    return 0;
}