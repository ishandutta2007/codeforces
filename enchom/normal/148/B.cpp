#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

int main()
{
    double pspeed;
    double dspeed;
    double girlplace=0,dragonplace=0;
    double dragonwait=0;
    double reach,f;
    Int bijeu=0;
    double dragonneeds,girlneeds;
    double x;
    bool backwards=false;
    double dragongo;
    
    cin>>pspeed>>dspeed>>dragonwait>>f>>reach;
    
    girlplace=dragonwait*pspeed;
    
    if (girlplace>=reach || dspeed<=pspeed)
    {
        printf("0\n");
        return 0;
    }
    
    while(1)
    {
        x=girlplace/(dspeed-pspeed);
        girlplace=girlplace+pspeed*x;
        dragonplace=girlplace;
        
        if (girlplace>=reach)
        break;
        
        bijeu++;
        
        x=dragonplace/dspeed;
        dragonplace=0;
        girlplace=girlplace+pspeed*x;
        
        girlplace=girlplace+pspeed*f;
    }
    printf("%I64d\n",bijeu);
    return 0;
}