#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N, M;
char S[100005];
char T[100005];
bool good[100005];
int R[100005];
int dp[100005];
int psum[100005];
const int X=127;
int P[100005];
int HS[100005];
int HT[100005];

inline int get(int *A, int l, int r)
{
    return (A[r]-1LL*A[l-1]*P[r-l+1]%MOD+MOD)%MOD;
}

int main()
{
    scanf("%s", S+1);
    scanf("%s", T+1);
    N=strlen(S+1);
    M=strlen(T+1);
    P[0]=1;
    for(int i=1; i<100005; i++)
        P[i]=(1LL*P[i-1]*X)%MOD;
    for(int i=1; i<=N; i++)
        HS[i]=(1LL*HS[i-1]*X+S[i])%MOD;
    for(int i=1; i<=M; i++)
        HT[i]=(1LL*HT[i-1]*X+T[i])%MOD;
    for(int i=1; i<=N-M+1; i++)
        if(get(HS, i, i+M-1)==HT[M])
            good[i]=true;
    R[N+1]=-1;
    for(int i=N; i>=1; i--)
        if(good[i])
            R[i]=i;
        else
            R[i]=R[i+1];
    dp[N+1]=1;
    psum[N+1]=1;
    for(int i=N; i>=1; i--)
    {
        dp[i]=dp[i+1];
        if(R[i]!=-1)
            dp[i]=(dp[i]+psum[R[i]+M])%MOD;
        psum[i]=(dp[i]+psum[i+1])%MOD;
    }
    printf("%d\n", (dp[1]-1+MOD)%MOD);
    return 0;
}