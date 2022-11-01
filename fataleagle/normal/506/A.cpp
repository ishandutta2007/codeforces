#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N, D;
int A[30001];
vector<int> _dp[800];
vector<int> *dp=_dp+400;

int main()
{
    scanf("%d%d", &N, &D);
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        A[a]++;
    }
    for(int i=0; i<800; i++)
        _dp[i].resize(30001, -1);
    dp[0][D]=A[D];
    int ans=A[D];
    for(int i=0; i<=30000; i++)
        for(int j=-350; j<=350; j++)
            if(dp[j][i]!=-1)
                for(int k=-1; k<=1; k++)
                    if(D+j+k>0 && i+D+j+k<=30000)
                        ans=max(ans, dp[j+k][i+D+j+k]=max(dp[j+k][i+D+j+k], dp[j][i]+A[i+D+j+k]));
    printf("%d\n", ans);
    return 0;
}