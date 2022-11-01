#include <bits/stdc++.h>

using namespace std;

int N;
int A[200000];
int B[200000];
int X[200000];
int Y[200000];
int Z[200001];
int bit[262144];

void add(int x, int v)
{
    for(x++; x<=N; x+=x&-x)
        bit[x]+=v;
}

int sum(int x)
{
    int ret=0;
    for(x++; x>0; x-=x&-x)
        ret+=bit[x];
    return ret;
}

int kth(int k)
{
    int lo=0, mid, hi=N-1;
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        if(sum(mid)<k)
            lo=mid+1;
        else
            hi=mid;
    }
    return lo;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+N-1-i);
    for(int i=0; i<N; i++)
        scanf("%d", B+N-1-i);
    for(int i=0; i<N; i++)
    {
        X[i]=sum(A[i]);
        add(A[i], 1);
    }
    memset(bit, 0, sizeof bit);
    for(int i=0; i<N; i++)
    {
        Y[i]=sum(B[i]);
        add(B[i], 1);
    }
    for(int i=0; i<N; i++)
    {
        Z[i]+=X[i]+Y[i];
        if(Z[i]>=i+1)
        {
            Z[i]-=i+1;
            Z[i+1]++;
        }
    }
    for(int i=N-1; i>=0; i--)
    {
        int x=kth(Z[i]+1);
        printf("%d ", x);
        add(x, -1);
    }
    printf("\n");
    return 0;
}