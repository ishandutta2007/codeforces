#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

struct seq
{
    Int start,len;
    char dig;
};

char str[500005];
Int sL=0;
seq se;

int main()
{
    Int n,k;
    Int i,j;
    char digit;
    Int changes=0;
    Int ch1=0,ch2=0;
    string s;
    
    scanf("%I64d %I64d",&n,&k);
    cin>>s;
    
    for (i=0;i<s.length();i++)
    {
        str[i+1]=s[i];
    }
    sL=s.length();
    
    ///
    if (k==2)
    {
        for (i=1;i<=sL;i++)
        {
            if (str[i]=='A')
            {
                if (i%2==1)
                ch2++;
                else
                ch1++;
            }
            else
            {
                if (i%2==1)
                ch1++;
                else
                ch2++;
            }
        }
        if (ch1<=ch2)
        {
            printf("%I64d\n",ch1);
            for (i=1;i<=sL;i++)
            {
                if (i%2==1)
                printf("A");
                else
                printf("B");
            }
        }
        else
        {
            printf("%I64d\n",ch2);
            for (i=1;i<=sL;i++)
            {
                if (i%2==1)
                printf("B");
                else
                printf("A");
            }
        }
        printf("\n");
        return 0;
    }
    ///
    str[sL+1]='/';
    
    se.len=0;
    se.start=-1;
    se.dig='.';
    for (i=1;i<=sL+1;i++)
    {
        if (str[i]==se.dig)
        {
            se.len++;
        }
        else
        {
            if (se.len>1)
            {
                if (se.dig!='A' && str[i]!='A')
                {
                    digit='A';
                }
                else if (se.dig!='B' && str[i]!='B')
                {
                    digit='B';
                }
                else
                {
                    digit='C';
                }
                for (j=se.start+1;j<=se.start+se.len-1;j+=2)
                {
                    changes++;
                    str[j]=digit;
                }
            }
            se.start=i;
            se.dig=str[i];
            se.len=1;
        }
    }
    printf("%I64d\n",changes);
    for (i=1;i<=sL;i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}