#include <bits/stdc++.h>

using namespace std;

int N;
int A[200000];
int B[200000];

int main()
{
    scanf("%d", &N);
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        A[i]=a+i;
    }
    sort(A, A+N);
    for(int i=N-1; i>=0; i--)
        B[i]=A[i]-i;
    bool good=true;
    for(int i=1; i<N; i++)
        if(B[i]<B[i-1])
            good=false;
    if(!good)
        printf(":(\n");
    else
    {
        for(int i=0; i<N; i++)
            printf("%d ", B[i]);
        printf("\n");
    }
    return 0;
}