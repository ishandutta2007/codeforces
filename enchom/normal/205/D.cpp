#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

struct LOL
{
    Int amount,num;
};

Int front[100001];
Int back[100001];
Int backs=0;
LOL froont[100001];
int fL=0,bL=0;
LOL baack[100001];

int main()
{
    Int n;
    Int i;
    Int uk;
    Int half;
    Int minim=999999999;
    
    scanf("%I64d",&n);
    
    backs=1;
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&front[i],&back[backs]);
        if (front[i]==back[backs])
        {
            backs--;
        }
        backs++;
    }
    backs--;
    sort(front+1,front+1+n);
    sort(back+1,back+1+backs);
    
    
    fL=1;
    froont[1].num=front[1];
    froont[1].amount=1;
    for (i=2;i<=n;i++)
    {
        if (front[i]==froont[fL].num)
        {
            froont[fL].amount++;
        }
        else
        {
            fL++;
            froont[fL].amount=1;
            froont[fL].num=front[i];
        }
    }
    
    
    if (backs>0)
    {
        bL=1;
        baack[1].num=back[1];
        baack[1].amount=1;
    }
    for (i=2;i<=backs;i++)
    {
        if (back[i]==baack[bL].num)
        {
            baack[bL].amount++;
        }
        else
        {
            bL++;
            baack[bL].amount=1;
            baack[bL].num=back[i];
        }
    }
    
    uk=1;
    half=(n+1)/2;
    for (i=1;i<=fL;i++)
    {
        if (froont[i].amount>=half)
        {
            minim=0;
        }
        else
        {
            while(1)
            {
                if (uk>bL)
                break;
                if (baack[uk].num<froont[i].num)
                uk++;
                else
                break;
            }
            if (uk>bL)
            break;
            
            if (baack[uk].num==froont[i].num)
            {
                if (baack[uk].amount>=half-froont[i].amount)
                {
                    if ( half-froont[i].amount<minim )
                    minim=half-froont[i].amount;
                }
            }
        }
    }
    
    for (i=1;i<=bL;i++)
    {
        if (baack[i].amount>=half)
        {
            if (half<minim)
            {
                minim=half;
                break;
            }
        }
    }
    if (minim==999999999)
    cout<<-1<<endl;
    else
    cout<<minim<<endl;
    return 0;
}