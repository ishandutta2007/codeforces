#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

char str[101];
Int sL=0;
char str2[101];
Int sL2=0;

int main()
{
    string s;
    Int i;
    Int uk;
    Int ukend;
    
    cin>>s;
    
    for (i=0;i<s.length();i++)
    {
        str[i+1]=s[i];
    }
    sL=s.length();
    
    if (str[1]=='h')
    {
        str2[1]='h';
        str2[2]='t';
        str2[3]='t';
        str2[4]='p';
        uk=5;
        sL2=4;
    }
    else
    {
        str2[1]='f';
        str2[2]='t';
        str2[3]='p';
        uk=4;
        sL2=3;
    }
    sL2++;
    str2[sL2]=':';
    sL2++;
    str2[sL2]='/';
    sL2++;
    str2[sL2]='/';
    
    for (i=uk;i<=sL;i++)
    {
        if (str[i]=='r' && str[i+1]=='u')
        {
            ukend=i-1;
        }
    }
    for (i=uk;i<=ukend;i++)
    {
        sL2++;
        str2[sL2]=str[i];
    }
    uk=ukend+3;
    sL2++;
    str2[sL2]='.';
    sL2++;
    str2[sL2]='r';
    sL2++;
    str2[sL2]='u';
    if (uk<=sL)
    {
        sL2++;
        str2[sL2]='/';
        for (i=uk;i<=sL;i++)
        {
            sL2++;
            str2[sL2]=str[i];
        }
    }
    for (i=1;i<=sL2;i++)
    printf("%c",str2[i]);
    printf("\n");
    return 0;
}