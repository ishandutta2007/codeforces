#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
typedef long long Int;

struct sms
{
    Int madeof[51];
    Int mdfL;
};

Int beautys[51];
map<Int,sms> mymap;
map<Int,sms>::iterator myit;
sms newsums[10001];
Int newsumvals[10001];
Int nsL=0;

int main()
{
    Int n,k;
    Int i,j,p;
    sms a;
    Int shown=0;
    
    for (i=0;i<=10000;i++)
    {
        newsums[i].mdfL=0;
    }
    
    scanf("%I64d %I64d",&n,&k);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&beautys[i]);
    }
    
    a.mdfL=0;
    mymap.insert( pair<Int,sms>(0,a) );
    
    for (p=1;p<=n;p++)
    {
        nsL=0;
        for (myit=mymap.begin();myit!=mymap.end();myit++)
        {
            nsL++;
            newsums[nsL].mdfL=((*myit).second).mdfL+1;
            newsumvals[nsL]=(*myit).first+beautys[p];
            for (j=1;j<=newsums[nsL].mdfL-1;j++)
            {
                newsums[nsL].madeof[j]=((*myit).second).madeof[j];
            }
            newsums[nsL].madeof[ newsums[nsL].mdfL ]=beautys[p];
        }
        for (i=1;i<=nsL;i++)
        {
            mymap.insert( pair<Int,sms>(newsumvals[i],newsums[i]) );
        }
        if (mymap.size()>k)
        {
            break;
        }
    }
    
    for (myit=mymap.begin();myit!=mymap.end();myit++)
    {
        if ((*myit).first==0)
        continue;
        
        printf("%I64d ",((*myit).second).mdfL);
        for (j=1;j<=((*myit).second).mdfL;j++)
        {
            printf("%I64d",((*myit).second).madeof[j]);
            if (j==((*myit).second).mdfL)
            printf("\n");
            else
            printf(" ");
        }
        shown++;
        if (shown==k)
        break;
    }
    return 0;
}