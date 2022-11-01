#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[100100], B[100100];
long long pA[100100], pB[100100];

long long solve(long long x)
{
    long long idx=lower_bound(A+1, A+1+N, x)-A-1;
    long long ret=x*idx-pA[idx];
    idx=upper_bound(B+1, B+1+M, x)-B-1;
    long long v=pB[M]-pB[idx]-x*(M-idx);
    return ret+v;
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=1; i<=M; i++)
        scanf("%d", B+i);
    if(*min_element(A+1, A+1+N)>=*max_element(B+1, B+1+M))
    {
        printf("0\n");
        return 0;
    }
    sort(A+1, A+1+N);
    sort(B+1, B+1+M);
    for(int i=1; i<=N; i++)
        pA[i]=pA[i-1]+A[i];
    for(int i=1; i<=M; i++)
        pB[i]=pB[i-1]+B[i];
    long long ans=0x3f3f3f3f3f3f3f3f;
    for(int i=1; i<=N; i++)
        ans=min(ans, solve(A[i]));
    for(int i=1; i<=M; i++)
        ans=min(ans, solve(B[i]));
    cout<<ans<<endl;
    return 0;
}