#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long Int;
typedef long double Double;

void EnchomSolve()
{
    int a,b,c;
    Double A,B,C;
    Double r1,r2;

    scanf("%d %d %d",&a,&b,&c);
    A=(Double)a;
    B=(Double)b;
    C=(Double)c;

    r1=(-B+sqrt(B*B-4.0*A*C))/(2.0*A);
    r2=(-B-sqrt(B*B-4.0*A*C))/(2.0*A);

    if (r1>r2)
    printf("%.8f\n%.8f\n",(double)r1,(double)r2);
    else
    printf("%.8f\n%.8f\n",(double)r2,(double)r1);

    return;
}

int main()
{
    EnchomSolve();
    return 0;
}