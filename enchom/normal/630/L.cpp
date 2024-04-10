#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

char str[10];
Int num;
const Int MOD=100000;

Int D(char ch)
{
    return (Int)ch-(Int)'0';
}

void EnchomSolve()
{
    Int rem;

    scanf("%s",str+1);

    num=D(str[1]);
    num=num*10+D(str[3]);
    num=num*10+D(str[5]);
    num=num*10+D(str[4]);
    num=num*10+D(str[2]);

    rem=num;

    num=num*rem*rem;
    num%=MOD;
    num=num*rem*rem;
    num%=MOD;

    if (num<10000)
    printf("0");
    if (num<1000)
    printf("0");
    if (num<100)
    printf("0");
    if (num<10)
    printf("0");
    printf("%lld\n",num);

    return;
}

int main()
{
    EnchomSolve();
    return 0;
}