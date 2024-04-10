#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, M;
int A[100001];
int B[100001];
int C[100001];
int L[2001], R[2001], nL, nR;
int V[200001];
int dp[100001];
int dp2[100001];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=1; i<=M; i++)
        scanf("%d", R+i), V[R[i]]=1;
    for(int i=1; i<=200000; i++)
        V[i]+=V[i-1];
    sort(A+1, A+1+N);
    B[1]=1;
    for(int i=2; i<=N; i++)
        if(A[i]==A[i-1]+1)
            B[i]=B[i-1];
        else
            B[i]=i;
    C[N]=N;
    for(int i=N-1; i>=1; i--)
        if(A[i+1]==A[i]+1)
            C[i]=C[i+1];
        else
            C[i]=i;
    sort(R+1, R+1+M, greater<int>());
    nR=M;
    for(int i=1; i<=N; i++)
    {
        dp[i]=max(dp[i], dp[i-1]);
        dp2[i]=max(dp2[i], dp[i-1]);
        while(nR>0 && R[nR]<=A[i])
            L[++nL]=R[nR--];
        if(i<N && A[i]+1==A[i+1])
            continue;
        for(int j=1; j<=nL; j++)
        {
            int len=A[i]-L[j]+1;
            if(len<=i)
                dp2[i]=max(dp2[i], dp[B[i-len+1]-1]+V[A[i]]-V[A[i]-(i-B[i-len+1])-1]);
        }
        dp[i]=max(dp[i], dp2[i]);
        for(int j=1; j<=nR; j++)
        {
            int len=R[j]-A[i]+1;
            if(len<=N-i+1)
                dp[C[i+len-1]]=max(dp[C[i+len-1]], dp2[i]+V[A[i]+(C[i+len-1]-i)]-V[A[i]]);
        }
    }
    printf("%d\n", dp[N]);
    return 0;
}