#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[101];

int main()
{
    scanf("%d%d", &N, &K);
    int mini=0x3f3f3f3f;
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), mini=min(mini, A[i]);
    int maxi=0;
    for(int i=1; i<=N; i++)
        maxi=max(maxi, A[i]-=mini);
    if(maxi>K)
    {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<mini; j++)
            printf("1 ");
        for(int j=1; j<=A[i]; j++)
            printf("%d ", j);
        printf("\n");
    }
    return 0;
}