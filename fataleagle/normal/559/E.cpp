#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> A[100];
int X[300], NX;
// fdp[i][j][k] - largest index such that at least <=j, k is covered by stuff from [ans, i]
int fdp[100][300][300];
// dp[i][j] - considering points after i, maximum value, but you can only use lamps >=j
int dp[300][100];
int pget[100][3];

int get(int x)
{
    return lower_bound(X, X+NX, x)-X;
}

int f(int idx, int l, int r)
{
    if(l<0 || r>=NX || idx<0)
        return -0x3f3f3f3f;
    if(l>=r)
        return idx;
    int& ret=fdp[idx][l][r];
    if(ret!=-1)
        return ret;
    ret=f(idx-1, l, r);
    for(int t=0; t<2; t++)
    {
        int a=-1, b=-1;
        if(t==0)
            a=pget[idx][0], b=pget[idx][1];
        else
            a=pget[idx][1], b=pget[idx][2];
        int x=b<r?f(idx-1, b, r):idx;
        int y=l<a?f(x-1, l, a):idx;
        ret=max(ret, min(x, y));
    }
    return ret;
}

int solve(int pos, int idx)
{
    if(pos>=NX || idx>=N)
        return 0;
    int& ret=dp[pos][idx];
    if(ret!=-1)
        return ret;
    ret=solve(pos+1, idx);
    for(int i=idx; i<N; i++)
        for(int j=pos+1; j<NX; j++)
            if(f(i, pos, j)>=idx)
                ret=max(ret, solve(j+1, i+1)+X[j]-X[pos]);
    return ret;
}

int main()
{
    memset(fdp, -1, sizeof fdp);
    memset(dp, -1, sizeof dp);
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &A[i].first, &A[i].second);
        X[i*3]=A[i].first-A[i].second;
        X[i*3+1]=A[i].first;
        X[i*3+2]=A[i].first+A[i].second;
    }
    sort(A, A+N);
    sort(X, X+3*N);
    NX=unique(X, X+3*N)-X;
    for(int i=0; i<N; i++)
    {
        pget[i][0]=get(A[i].first-A[i].second);
        pget[i][1]=get(A[i].first);
        pget[i][2]=get(A[i].first+A[i].second);
    }
    printf("%d\n", solve(0, 0));
    return 0;
}