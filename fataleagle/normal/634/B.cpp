#include <bits/stdc++.h>

using namespace std;

long long s, x;

int main()
{
    scanf("%lld%lld", &s, &x);
    int sub=0;
    if(s==x)
        sub=2;
    int pop=__builtin_popcountll(x);
    for(int i=0; i<60; i++)
        if((x>>i)&1)
            s-=1LL<<i;
    for(int i=59; i>=0; i--)
        if(!((x>>i)&1) && s>=(1LL<<(i+1)))
            s-=1LL<<(i+1);
    long long ans=1LL<<pop;
    if(s==0)
        printf("%lld\n", ans-sub);
    else
        printf("0\n");
    return 0;
}