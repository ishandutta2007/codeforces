#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N, M, K;
char S[1000002];
int dp[2000002];
int last[26];

void addmod(int& x, int v)
{
    x+=v;
    if(x>=MOD)
        x-=MOD;
}

int main()
{
    scanf("%d%d", &N, &K);
    scanf("%s", S+1);
    M=strlen(S+1);
    dp[0]=1;
    for(int i=1; i<=M; i++)
    {
        dp[i]=dp[i-1];
        addmod(dp[i], dp[i-1]);
        if(last[S[i]-'a']!=0)
            addmod(dp[i], MOD-dp[last[S[i]-'a']-1]);
        last[S[i]-'a']=i;
    }
    for(int i=M+1; i<=M+N; i++)
    {
        dp[i]=dp[i-1];
        addmod(dp[i], dp[i-1]);
        int let=0;
        for(int j=1; j<K; j++) if(last[j]<last[let])
            let=j;
        if(last[let]!=0)
            addmod(dp[i], MOD-dp[last[let]-1]);
        last[let]=i;
    }
    printf("%d\n", dp[N+M]);
    return 0;
}