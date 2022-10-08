#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long Int;

struct tdiv
{
    Int themain;
    bool used;
};

bool enabled[100001];
tdiv divisors[100001];

void RemoteControlEnable(Int a)
{
    if (enabled[a])
    {
        printf("Already on\n");
        return;
    }
    Int divs[50];
    Int divL=0;
    Int i;
    Int org=a;
    
    for (i=2;i*i<=a;i++)
    {
        if (a%i==0)
        {
            if (divisors[i].used)
            {
                printf("Conflict with %I64d\n",divisors[i].themain);
                return;
            }
            else
            {
                divL++;
                divs[divL]=i;
            }
            while(a%i==0)
            {
                a=a/i;
            }
        }
    }
    if (a>1)
    {
        if (divisors[a].used)
        {
            printf("Conflict with %I64d\n",divisors[a].themain);
            return;
        }
        else
        {
            divL++;
            divs[divL]=a;
            a=1;
        }
    }
    for (i=1;i<=divL;i++)
    {
        divisors[ divs[i] ].used=true;
        divisors[ divs[i] ].themain=org;
    }
    enabled[org]=true;
    printf("Success\n");
    return;
}

void RemoteControlDisable(Int a)
{
    if (!enabled[a])
    {
        printf("Already off\n");
        return;
    }
    Int i,org=a;
    
    for (i=2;i*i<=a;i++)
    {
        if (a%i==0)
        {
            divisors[i].used=false;
            while (a%i==0)
            a=a/i;
        }
    }
    if (a>1)
    {
        divisors[a].used=false;
        a=1;
    }
    enabled[org]=false;
    printf("Success\n");
    return;
}

int main()
{
    Int n,m;
    Int i;
    char ch;
    Int a;
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=0;i<=100000;i++)
    {
        enabled[i]=false;
        divisors[i].used=false;
    }
    
    for (i=1;i<=m;i++)
    {
        cin>>ch;
        scanf("%I64d",&a);
        
        if (ch=='+')
        RemoteControlEnable(a);
        else if (ch=='-')
        RemoteControlDisable(a);
    }
    return 0;
}