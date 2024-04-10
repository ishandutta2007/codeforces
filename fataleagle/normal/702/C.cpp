#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[100001];
int B[100001];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=1; i<=M; i++)
        scanf("%d", B+i);
    int ans=0;
    for(int i=1; i<=N; i++)
    {
        int pos=lower_bound(B+1, B+1+M, A[i])-B;
        int d=2147000000;
        if(pos>1)
            d=min(d, A[i]-B[pos-1]);
        if(pos<=M)
            d=min(d, B[pos]-A[i]);
        ans=max(ans, d);
    }
    printf("%d\n", ans);
    return 0;
}