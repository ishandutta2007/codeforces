#include <bits/stdc++.h>

using namespace std;

int N, M;
int dp[2][23][1<<20];
char S[100001];
int A[100000];

int c1(int x, int p)
{
    return (x-p)/2;
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
    {
        scanf("%s", S);
        for(int j=0; j<M; j++)
            A[j]|=(S[j]-'0')<<i;
    }
    for(int i=0; i<M; i++)
        dp[0][11][A[i]]++;
    for(int stage=0; stage<N; stage++)
    {
        int c=stage&1;
        for(int delta=-stage-1; delta<=stage+1; delta++)
            for(int i=0; i<(1<<N); i++)
                dp[c^1][c1(delta, c^1)+11][i]=0;
        for(int delta=-stage; delta<=stage; delta++) if((delta&1)==c)
        {
            for(int i=0; i<(1<<stage); i++)
            {
                for(int j=0; j<(1<<(N-stage)); j++)
                {
                    int now=dp[c][c1(delta, c)+11][(j<<stage)|i];
                    if(j&1)
                    {
                        dp[c^1][c1(delta+1, c^1)+11][((j>>1)<<(stage+1))|(i<<1)|0]+=now;
                        dp[c^1][c1(delta-1, c^1)+11][((j>>1)<<(stage+1))|(i<<1)|1]+=now;
                    }
                    else
                    {
                        dp[c^1][c1(delta+1, c^1)+11][((j>>1)<<(stage+1))|(i<<1)|1]+=now;
                        dp[c^1][c1(delta-1, c^1)+11][((j>>1)<<(stage+1))|(i<<1)|0]+=now;
                    }
                }
            }
        }
    }
    int ans=0x3f3f3f3f;
    for(int j=0; j<(1<<N); j++)
    {
        int sum=0;
        for(int i=-N; i<=N; i++) if((i&1)==(N&1))
            sum+=(N-abs(i))/2*dp[N&1][c1(i, N&1)+11][j];
        ans=min(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}