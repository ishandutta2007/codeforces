#include<iostream>
#include<cstdio>
using namespace std;
long long t,n,m;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        if(n&1)
        {
            m=(m-1)%(n*(n-1)/2)+1;
            int p=(m-1)/(n>>1);
            m+=p;
            printf("%lld\n",(m-1)%n+1);
        }
        else
            printf("%lld\n",(m-1)%n+1);
    }
    return 0;
}