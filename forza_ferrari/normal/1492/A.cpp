#include<iostream>
#include<cstdio>
using namespace std;
long long t,p,a,b,c;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
        printf("%lld\n",min(a-((p-1)%a+1),min(b-((p-1)%b+1),c-((p-1)%c+1))));
    }
    return 0;
}