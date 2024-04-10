#include <bits/stdc++.h>

using namespace std;

int N, H;
double P;
int A[2000];
int L[2000];
int R[2000];
double dp[2000][2000][2][2];

double rec(int l, int r, int wl, int wr)
{
    if(l>r)
        return 0.0;
    double& ret=dp[l][r][wl][wr];
    if(ret==ret)
        return ret;
    ret=0.0;
    int p=-0x3f3f3f3f;
    if(l!=0)
    {
        if(wl==0)
            p=A[l-1];
        else
            p=A[l-1]+H;
    }
    int n=0x3f3f3f3f;
    if(r!=N-1)
    {
        if(wr==0)
            n=A[r+1]-H;
        else
            n=A[r+1];
    }
    double cll=0.0, clr=0.0, crl=0.0, crr=0.0;
    cll=A[l]-max(p, A[l]-H)+rec(l+1, r, 0, wr);
    crr=min(n, A[r]+H)-A[r]+rec(l, r-1, wl, 1);
    clr=min(n, A[R[l]]+H)-A[l]+rec(R[l]+1, r, 1, wr);
    crl=A[r]-max(p, A[L[r]]-H)+rec(l, L[r]-1, wl, 0);
    ret=(P*cll+(1.0-P)*clr+P*crl+(1.0-P)*crr)/2;
    return ret;
}

int main()
{
    scanf("%d%d%lf", &N, &H, &P);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    sort(A, A+N);
    for(int i=0; i<N; i++)
        L[i]=R[i]=i;
    for(int i=1; i<N; i++) if(A[i]-A[i-1]<H)
        L[i]=L[i-1];
    for(int i=N-2; i>=0; i--) if(A[i+1]-A[i]<H)
        R[i]=R[i+1];
    memset(dp, -1, sizeof dp);
    printf("%.15f\n", rec(0, N-1, 0, 0));
    return 0;
}