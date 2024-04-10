#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long Int;

Int TOINT(char ch)
{
    return (Int)(ch-'0');
}

int main()
{
    string a;
    Int hours,minutes;
    
    cin>>a;
    
    hours=TOINT(a[0]);
    hours=hours*10+TOINT(a[1]);
    
    minutes=TOINT(a[3]);
    minutes=minutes*10+TOINT(a[4]);
    
    while(1)
    {
        minutes++;
        if (minutes==60)
        {
            minutes=0;
            hours++;
        }
        if (hours==24)
        {
            hours=0;
        }
        
        if (hours/10==minutes%10 && minutes/10==hours%10)
        {
            break;
        }
    }
    if (hours<10)
    printf("0");
    printf("%I64d",hours);
    
    printf(":");
    
    if (minutes<10)
    printf("0");
    printf("%I64d\n",minutes);
    
    return 0;
}