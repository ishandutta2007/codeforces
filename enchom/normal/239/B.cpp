#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int str[101];
Int repairstr[101];
Int sL=0;
Int nums[10];

void Initializate()
{
    Int i;
    
    for (i=0;i<=9;i++)
    nums[i]=0;
    
    return;
}
void Print()
{
    Int i;
    for (i=0;i<=9;i++)
    {
        printf("%I64d",nums[i]);
        if (i!=9)
        printf(" ");
        else
        printf("\n");
    }
    return;
}

Int ABS(Int a)
{
    if (a<0)
    return a*-1;
    else
    return a;
}

void Calculate(Int l,Int r)
{
    bool TFO[101];
    Int i;
    Int CP=l,DP=1;
    Int lastchar=0;
    
    for (i=0;i<=100;i++)
    TFO[i]=false;
    
    while(CP>=l && CP<=r)
    {
        if (TFO[CP])
        {
            if (DP==1)
            CP++;
            else
            CP--;
            
            continue;
        }
        
        if (str[CP]>=0)
        {
            nums[ str[CP] ]++;
            
            str[CP]--;
            
            lastchar=CP;
            
            if (str[CP]<0)
            {
                TFO[CP]=true;
            }

            
            if (DP==1)
            CP++;
            else
            CP--;
        }
        else
        {
            DP=ABS( str[CP] );
            
            if ( str[lastchar]<0 )
            {
                TFO[lastchar]=true;
            }
            lastchar=CP;
            
            if (DP==1)
            CP++;
            else
            CP--;
        }
    }
}

void Repair()
{
    Int i;
    for (i=0;i<=100;i++)
    {
        str[i]=repairstr[i];
    }
    return;
}

int main()
{
    Int n,q;
    Int i;
    string s;
    Int l,r;
    
    scanf("%I64d %I64d",&n,&q);
    
    cin>>s;
    str[0]='.';
    
    for (i=0;i<s.length();i++)
    {
        if (s[i]>='0' && s[i]<='9')
        {
            str[i+1]=(Int)(s[i]-'0');
        }
        else
        {
            if (s[i]=='>')
            str[i+1]=-1;
            else
            str[i+1]=-2;
        }
        repairstr[i+1]=str[i+1];
    }
    
    for (i=1;i<=q;i++)
    {
        scanf("%I64d %I64d",&l,&r);
        
        Initializate();
        Calculate(l,r);
        Print();
        Repair();
    }
    return 0;
}