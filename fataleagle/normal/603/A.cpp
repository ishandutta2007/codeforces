#include <bits/stdc++.h>

using namespace std;

int N;
char S[100002];
int A[100001];
int dp[100001][3][2];

int rec(int pos, int state, int last)
{
    if(pos==N+1)
        return 0;
    int& ret=dp[pos][state][last];
    if(ret!=-1)
        return ret;
    ret=0;
    if(state==0)
        ret=max(ret, (last^A[pos])+rec(pos+1, 0, A[pos]));
    if(state==0 || state==1)
        ret=max(ret, (last^A[pos]^1)+rec(pos+1, 1, A[pos]^1));
    if(state==1 || state==2)
        ret=max(ret, (last^A[pos])+rec(pos+1, 2, A[pos]));
    return ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d", &N);
    scanf("%s", S+1);
    for(int i=1; i<=N; i++)
        A[i]=S[i]-'0';
    printf("%d\n", max(rec(1, 0, 0), rec(1, 0, 1)));
    return 0;
}