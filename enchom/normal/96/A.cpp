#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

int main()
{
    Int i;
    string a;
    Int inarow;
    bool one=true;
    
    cin>>a;
    
    inarow=0;
    
    for (i=0;i<a.length();i++)
    {
        if (a[i]=='1')
        {
            if (one)
            {
                inarow++;
                if (inarow>=7)
                {
                    printf("YES\n");
                    return 0;
                }
            }
            else
            {
                one=true;
                inarow=1;
            }
        }
        else
        {
            if (one)
            {
                one=false;
                inarow=1;
            }
            else
            {
                inarow++;
                if (inarow>=7)
                {
                    printf("YES\n");
                    return 0;
                }
            }
        }
    }
    printf("NO\n");
    return 0;
}