#include <bits/stdc++.h>

using namespace std;

int N;
int A[100];
int dp[100];

int rec(int pos)
{
    if(pos>N)
        return 0;
    int& ret=dp[pos];
    if(ret!=-1)
        return ret;
    ret=max(rec(pos+1)-A[pos], A[pos]-rec(pos+1));
    return ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d", &N);
    int s=0;
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), s+=A[i];
    int ans=rec(1);
    printf("%d %d\n", (s-ans)/2, (s+ans)/2);
    return 0;
}