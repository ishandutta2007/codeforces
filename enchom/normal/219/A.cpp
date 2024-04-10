#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int digits[26];
Int newdig[26];

int main()
{
    Int k;
    string s;
    Int i,j,in;
    
    scanf("%I64d",&k);
    cin>>s;
    
    for (i=0;i<=25;i++)
    {
        digits[i]=0;
        newdig[i]=0;
    }
    
    for (i=0;i<s.length();i++)
    {
        digits[ s[i]-'a' ]++;
    }
    
    for (i=0;i<=25;i++)
    {
        if (digits[i]%k!=0)
        {
            printf("-1\n");
            return 0;
        }
        newdig[i]=digits[i]/k;
    }
    
    for (i=1;i<=k;i++)
    {
        for (j=0;j<=25;j++)
        {
            for (in=1;in<=newdig[j];in++)
            {
                printf("%c",(char)(j+'a'));
            }
        }
    }
    printf("\n");
    return 0;
}