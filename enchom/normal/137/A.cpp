#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long Int;


int main()
{
    string k;
    Int i;
    bool photo;
    Int holding=0;
    Int returns=0;
    bool unknown=true;
    
    cin>>k;
    
    
    for (i=0;i<k.length();i++)
    {
        if (k[i]=='P')
        {
            if (unknown)
            {
                photo=true;
                holding++;
                unknown=false;
            }
            else if (photo)
            {
                holding++;
                if (holding==5)
                {
                    returns++;
                    holding=0;
                    unknown=true;
                }
            }
            else
            {
                returns++;
                holding=1;
                photo=true;
            }
        }
        if (k[i]=='C')
        {
            if (unknown)
            {
                holding++;
                photo=false;
                unknown=false;
            }
            else if (photo)
            {
                returns++;
                holding=1;
                photo=false;
            }
            else
            {
                holding++;
                if (holding==5)
                {
                    returns++;
                    holding=0;
                    unknown=true;
                }
            }
        }
    }
    if (holding>0)
    {
        returns++;
    }
    printf("%I64d\n",returns);
    return 0;
}