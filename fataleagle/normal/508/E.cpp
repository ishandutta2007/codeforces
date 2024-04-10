#include <bits/stdc++.h>

using namespace std;

int N;
int L[601], R[601];
int dp[601][601];
int path[601][601];
char ans[1300];

int solve(int l, int r)
{
    if(l<0 || r>N || l>r)
        return 0;
    int& ret=dp[l][r];
    if(ret!=-1)
        return ret;
    if(l==r)
        return ret=L[l]==1;
    for(int i=L[l]; i<=R[l]; i++)
        if(i&1)
        {
            int val=1;
            if(i>1 && !solve(l+1, l+i/2))
                val=0;
            if(l+i/2!=r && !solve(l+i/2+1, r))
                val=0;
            if(val)
            {
                path[l][r]=i;
                return ret=1;
            }
        }
    return ret=0;
}

void trace(int l, int r, int offs)
{
    if(l==r)
    {
        ans[offs]='(';
        ans[offs+1]=')';
        return;
    }
    ans[offs]='(';
    ans[offs+path[l][r]]=')';
    if(path[l][r]>1)
        trace(l+1, l+path[l][r]/2, offs+1);
    if(l+path[l][r]/2!=r)
        trace(l+path[l][r]/2+1, r, offs+path[l][r]+1);
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d%d", L+i, R+i);
    if(!solve(1, N))
        printf("IMPOSSIBLE\n");
    else
    {
        trace(1, N, 1);
        puts(ans+1);
    }
    return 0;
}