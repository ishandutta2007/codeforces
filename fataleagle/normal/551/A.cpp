#include <bits/stdc++.h>

using namespace std;

int N;
int A[2000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    for(int i=0; i<N; i++)
    {
        int ans=1;
        for(int j=0; j<N; j++) if(A[j]>A[i])
            ans++;
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}