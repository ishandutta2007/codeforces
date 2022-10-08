#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int main()
{
    string s;
    Int i,j,in;
    Int peopleinside;
    Int maximumpeopleinside,minimumtotalpeopleinside=999999999;
    bool possible;
    
    cin>>s;
    
    for (i=0;i<=301;i++)
    {
        peopleinside=i;
        maximumpeopleinside=i;
        possible=true;
        
        for (j=0;j<s.length();j++)
        {
            if (s[j]=='-')
            {
                peopleinside--;
                if (peopleinside<0)
                {
                    possible=false;
                    break;
                }
            }
            else
            {
                peopleinside++;
                if (peopleinside>maximumpeopleinside)
                maximumpeopleinside=peopleinside;
            }
        }
        if (!possible)
        continue;
        else
        {
            if (maximumpeopleinside<minimumtotalpeopleinside)
            {
                minimumtotalpeopleinside=maximumpeopleinside;
            }
        }
    }
    
    printf("%I64d\n",minimumtotalpeopleinside);
    
    return 0;
}