#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long t,n;
int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",((long long)(sqrt((n<<1)-1))-1)>>1);
    }
    return 0;
}