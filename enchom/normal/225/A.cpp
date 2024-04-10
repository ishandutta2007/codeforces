#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int ways=0;
Int side1[101],side2[101];
bool minitfo[8];
Int n;

void batrak(Int dice,Int different)
{
    if (ways>=2)
    return;
    
    if (dice>n)
    {
        ways++;
        return;
    }
    Int i;
    bool fl;
    Int n1,n2;
    for (i=1;i<=7;i++)
    minitfo[i]=false;
    
    minitfo[ side1[dice] ]=true;
    minitfo[ 7-side1[dice] ]=true;
    minitfo[ 7-side2[dice] ]=true;
    minitfo[ side2[dice] ]=true;
    
    fl=true;
    for (i=1;i<=7;i++)
    {
        if (!minitfo[i])
        {
            if (fl)
            {
                n1=i;
                fl=false;
            }
            else
            {
                n2=i;
                break;
            }
        }
    }
    if (n1!=different)
    {
        batrak(dice+1,n2);
    }
    if (n2!=different)
    {
        batrak(dice+1,n1);
    }
}

int main()
{
    Int k;
    Int i;
    
    scanf("%I64d",&n);
    scanf("%I64d",&k);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&side1[i],&side2[i]);
    }
    batrak(2,7-k);
    
    if (ways>=2)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
    return 0;
}