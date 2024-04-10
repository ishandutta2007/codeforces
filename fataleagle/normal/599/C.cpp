#include <bits/stdc++.h>

using namespace std;

int N;
int A[100001];
int L[100001];
int R[100001];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    R[N]=A[N];
    for(int i=N-1; i>=1; i--)
        R[i]=min(R[i+1], A[i]);
    L[1]=A[1];
    for(int i=2; i<=N; i++)
        L[i]=max(L[i-1], A[i]);
    int ans=1;
    for(int i=2; i<=N; i++)
    {
        if(L[i-1]<=R[i])
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}