#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

char s[100001],p[100001];
Int sL=0,pL=0;

char current[100001];
Int beg=0,end=0;

Int letters[30],qmarks=0;
Int pletters[30];

bool OK()
{
    Int toadd=0;
    Int i;
    
    for (i=0;i<=29;i++)
    {
        if (letters[i]>pletters[i])
        return false;
        else if (letters[i]<pletters[i])
        {
            toadd=toadd+(pletters[i]-letters[i]);
        }
    }
    if (toadd==qmarks)
    return true;
    else
    return false;
}

int main()
{
    string a,b;
    Int i;
    Int substrings=0;
    
    for (i=0;i<=29;i++)
    {
        letters[i]=0;
        pletters[i]=0;
    }
    
    
    cin>>a>>b;
    
    if (b.length()>a.length())
    {
        printf("0\n");
        return 0;
    }
    
    for (i=0;i<a.length();i++)
    {
        s[i+1]=a[i];
    }
    sL=a.length();
    for (i=0;i<b.length();i++)
    {
        p[i+1]=b[i];
    }
    pL=b.length();
    
    for (i=1;i<=pL;i++)
    {
        pletters[ p[i]-'a' ]++;
    }
    for (i=1;i<=pL;i++)
    {
        if (s[i]!='?')
        {
            letters[ s[i]-'a' ]++;
        }
        else
        {
            qmarks++;
        }
        end++;
        current[end]=s[i];
    }
    beg=1;
    
    if (OK())
    {
        substrings++;
    }
    
    for (i=pL+1;i<=sL;i++)
    {
        if ( s[i]!='?' )
        {
            letters[ s[i]-'a' ]++;
        }
        else
        {
            qmarks++;
        }
        
        end++;
        current[end]=s[i];
        
        if ( current[beg]!='?' )
        {
            letters[ current[beg]-'a' ]--;
        }
        else
        {
            qmarks--;
        }
        beg++;
        
        if(OK())
        substrings++;
    }
    printf("%I64d\n",substrings);
    return 0;
}