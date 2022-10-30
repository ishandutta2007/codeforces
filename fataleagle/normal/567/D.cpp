#include <bits/stdc++.h>

using namespace std;

int N, K, W, M;
int A[200000];
int B[200000];

int solve(int X)
{
    for(int i=0; i<=X; i++)
        B[i]=A[i];
    sort(B, B+X+1);
    int ret=0;
    if(B[0]>W)
        ret+=1+(B[0]-1-W)/(W+1);
    if(N-B[X]>=W)
        ret+=1+(N-B[X]-W)/(W+1);
    for(int i=1; i<=X; i++)
        if(B[i]-B[i-1]-1>=W)
            ret+=1+(B[i]-B[i-1]-1-W)/(W+1);
    return ret;
}

int main()
{
    scanf("%d%d%d", &N, &K, &W);
    scanf("%d", &M);
    for(int i=0; i<M; i++)
        scanf("%d", A+i);
    int lo=0, mid, hi=M;
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        if(solve(mid)<K)
            hi=mid;
        else
            lo=mid+1;
    }
    if(lo==M)
        printf("-1\n");
    else
        printf("%d\n", lo+1);
    return 0;
}