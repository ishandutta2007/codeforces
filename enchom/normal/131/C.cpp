#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long Int;

Int Ways(Int todo,Int from)
{
    Int one,two;
    Int bigger;
    Int ans=1;
    Int i,j;
    bool TFO[31];
    
    for (i=0;i<=30;i++)
    TFO[i]=false;
    
    one=todo;
    two=from-todo;
    
    if (two==0)
    return 1;
    
    if (one>two)
    bigger=one;
    else
    bigger=two;
    
    for (i=bigger+1;i<=from;i++)
    {
        ans=ans*i;
        
        for (j=1;j<=from-bigger;j++)
        {
            if (ans%j==0 && !TFO[j])
            {
                TFO[j]=true;
                ans=ans/j;
            }
        }
    }
    return ans;
}

int main()
{
    Int n,m,t;
    Int i;
    Int boys,girls;
    Int waystodoit=0;
    
    scanf("%I64d %I64d %I64d",&n,&m,&t);
    
    for (i=1;i<=t-4 && i<=m;i++)
    {
        boys=t-i;
        girls=i;
        if (boys>n)
        continue;
        
        waystodoit=waystodoit+Ways(boys,n)*Ways(girls,m);
    }
    printf("%I64d\n",waystodoit);
    return 0;
}