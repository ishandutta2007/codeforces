#include<iostream>
#include<fstream>
using namespace std;

long long k,n,s,p;

int main()
{
    scanf("%I64d%I64d%I64d%I64d",&k,&n,&s,&p);
    printf("%I64d",(((n+s-1)/s)*k+p-1)/p);
    return 0;
}