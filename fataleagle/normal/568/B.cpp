#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N;

int S2[4001][4001];

int main()
{
    for(int i=1; i<=4000; i++)
        for(int j=1; j<=4000; j++)
        {
            if(i==1 && j==1)
                S2[i][j]=1;
            else if(i==1)
                S2[i][j]=0;
            else
                S2[i][j]=(1LL*j*S2[i-1][j]+S2[i-1][j-1])%MOD;
        }
    scanf("%d", &N);
    int ans=0;
    for(int i=1; i<=N; i++)
        ans=(ans+1LL*i*S2[N][i])%MOD;
    printf("%d\n", ans);
    return 0;
}