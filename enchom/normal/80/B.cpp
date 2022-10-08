#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

char clock[10];

Int INT(char ch)
{
    return (Int)ch-(Int)'0';
}

int main()
{
    Int i;
    Int hs,ms;
    
    double degreesH,degreesM;
    
    scanf("%s",clock);
    
    hs=INT(clock[0])*10+INT(clock[1]);
    hs=hs%12;
    
    ms=INT(clock[3])*10+INT(clock[4]);
    
    degreesM=6.0*(double)ms;
    degreesH=(double)hs*30.0 + ( ms*0.5 );
    
    printf("%4.9f %4.9f\n",degreesH,degreesM);
    return 0;
}