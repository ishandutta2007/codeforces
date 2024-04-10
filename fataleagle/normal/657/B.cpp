#include <bits/stdc++.h>

using namespace std;

int N, K;
int C[300000];
int A[300000];
int B[300000];
int Q[300000];

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=0; i<=N; i++)
    {
        scanf("%d", C+i);
        if(C[i]>0)
            A[i]+=C[i];
        else
            B[i]+=-C[i];
    }
    int hiA=0, hiB=0;
    long long x=0;
    for(int i=0; i<=N || x>0; i++)
    {
        x+=A[i];
        A[i]=x%2;
        x/=2;
        if(A[i])
            hiA=i;
    }
    x=0;
    for(int i=0; i<=N || x>0; i++)
    {
        x+=B[i];
        B[i]=x%2;
        x/=2;
        if(B[i])
            hiB=i;
    }
    bool flip=false;
    if(hiA<hiB)
        flip=true;
    if(!flip)
    {
        for(int i=hiA; i>=0; i--) if(A[i]!=B[i])
        {
            if(B[i])
                flip=true;
            break;
        }
    }
    if(flip)
    {
        for(int i=0; i<=max(hiA, hiB); i++)
        {
            swap(A[i], B[i]);
            C[i]*=-1;
        }
    }
    int carry=0;
    int hiQ=0;
    for(int i=0; i<=max(hiA, hiB); i++)
    {
        if(carry)
        {
            A[i]--;
            carry=0;
        }
        if(A[i]<B[i])
        {
            A[i]+=2;
            carry=1;
        }
        Q[i]=A[i]-B[i];
        if(Q[i])
            hiQ=i;
    }
    int ans=0;
    for(int i=0; i<=min(hiQ, N); i++)
    {
        if(i+40<hiQ)
            continue;
        x=0;
        for(int j=hiQ; j>=i; j--)
            x=x*2+Q[j];
        if(C[i]-x>=-K && (C[i]-x!=0 || i!=N))
            ans++;
        if(Q[i]==1)
            break;
    }
    printf("%d\n", ans);
    return 0;
}