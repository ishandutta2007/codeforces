#include<iostream>
#include<fstream>
using namespace std;
long long n;
int main()
{
    scanf("%I64d",&n);
    if(n==0)printf("0");
    else if(n%2)printf("%I64d",n/2+1);
    else printf("%I64d",n+1);
    return 0;
}