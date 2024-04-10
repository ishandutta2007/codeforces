#include <bits/stdc++.h>

using namespace std;

int N;
int A[5000];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    printf("%d\n", N);
    for(int i=1; i<=N; i++)
    {
        int best=0x3f3f3f3f, idx=-1;
        for(int j=1; j<=N; j++)
            if(A[j]!=-0x3f3f3f3f && A[j]<best)
                best=A[j], idx=j;
        printf("%d %d\n", i-1, idx-1);
        A[idx]=-0x3f3f3f3f;
        swap(A[i], A[idx]);
    }
    return 0;
}