#include <bits/stdc++.h>

using namespace std;

long long f(long long n)
{
    if(n<0)
        return 0;
    n+=2;
    return n*(n-1)/2;
}

long long solve(int a, int b, int c, int n)
{
    long long ret=0;
    ret+=f(n);
    ret-=f(n-a-1);
    ret-=f(n-b-1);
    ret-=f(n-c-1);
    ret+=f(n-a-b-2);
    ret+=f(n-b-c-2);
    ret+=f(n-c-a-2);
    ret-=f(n-a-b-c-3);
    return ret;
}

int main()
{
    int A, B, C, L;
    scanf("%d%d%d%d", &A, &B, &C, &L);
    long long ans=0;
    for(int i=0; i<=L; i++)
    {
        int s=A+B+C+i;
        int ml=(s-1)/2;
        if(A<=ml && B<=ml && C<=ml)
            ans+=solve(ml-A, ml-B, ml-C, i);
    }
    printf("%lld\n", ans);
    return 0;
}