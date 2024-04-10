#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

struct palindrome
{
    Int str,end;
};

palindrome palindromes[5000001];
bool existpal[2001][2001];
Int pL=0;
char s[2001];
Int n;
string inp;

int main()
{
    Int i,j;
    Int theend,thestart;
    Int morethan,l,r,mid;
    Int found,total=0;
    Int ctr=0;
    
    cin>>inp;
    
    n=inp.length();
    for (i=0;i<n;i++)
    {
        s[i+1]=inp[i];
    }
    for (i=0;i<=2000;i++)
    {
        for (j=0;j<=2000;j++)
        existpal[i][j]=false;
    }
    for (i=1;i<=n;i++)
    {
        theend=i;
        thestart=i;
        while( s[theend]==s[thestart] && theend<=n && thestart>=1 )
        {
            existpal[thestart][theend]=true;
            
            thestart--;
            theend++;
        }
        
        if (i!=n)
        {
            theend=i+1;
            thestart=i;
            while( s[theend]==s[thestart] && theend<=n && thestart>=1 )
            {
                existpal[thestart][theend]=true;
            
                thestart--;
                theend++;
            }
        }
    }
    
    for (i=1;i<=n;i++)
    {
        for (j=i;j<=n;j++)
        {
            if (existpal[i][j])
            {
                pL++;
                palindromes[pL].str=i;
                palindromes[pL].end=j;
            }
        }
    }
    
    
    for (i=1;i<=pL;i++)
    {
        morethan=palindromes[i].end;
        l=1;
        r=pL;
        found=-1;
        while(l<=r)
        {
            mid=(l+r)/2;
            if (palindromes[mid].str>morethan)
            {
                found=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        if (found!=-1)
        {
            total=total+(pL-found+1);
        }
    }
    printf("%I64d\n",total);
    return 0;
}