#include <bits/stdc++.h>

using namespace std;

int N;
int A[100001];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=N; i>=1; i--)
        A[i]-=A[i-1];
    int a=0, b=0;
    for(int i=1; i<=N; i++)
    {
        if(A[i]>=0)
            a++;
        else
            a=1;
        b=max(b, a);
    }
    printf("%d\n", b);
    return 0;
}