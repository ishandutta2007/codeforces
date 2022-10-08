#include <iostream>
#include <stdio.h>
using namespace std;

long long FastPowering(long long k,long long p,long long m) //Calculate k^p mod m fast
{
    if (p==0)
    return 1%m; //could be 0 if m=1, otherwise it's 1

    if (p%2==0)
    {
        long long ans=FastPowering(k,p/2,m);
        ans=(ans*ans)%m;
        return ans; //returning (k^(p/2))^2 = k^p
    }
    else
    {
        long long ans=FastPowering(k,p/2,m);
        ans=(ans*ans)%m;
        ans=(ans*k)%m;
        return ans; //returning (k^(p/2))^2*k = k^p since p/2 is integer division
    }
}

int main()
{
    long long n,m;
    long long power;
    long long answer;

    scanf("%I64d %I64d",&n,&m); //input

    power=FastPowering(3,n,m); //calculating 3^n mod m for O(log N)

    answer=power-1; //answer is 3^n-1

    if (answer<0) //could happen if 3^n gave 0 modulo m
    answer=answer+m;

    printf("%I64d\n",answer); //output

    return 0;
}