#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long Int;

Int nums[100001];
Int nL=0;

int main()
{
    string k;
    Int i;
    Int newnum;
    Int ctr=0;
    
    cin>>k;
    
    for (i=0;i<k.length();i++)
    {
        nums[i+1]=k[i]-'0';
    }
    nL=k.length();
    
    while(nL>1)
    {
        ctr++;
        newnum=0;
        for (i=1;i<=nL;i++)
        {
            newnum=newnum+nums[i];
        }
        nL=0;
        
        if (newnum==0)
        nL=1;
        
        while(newnum>0)
        {
            nL++;
            nums[nL]=newnum%10;
            newnum=newnum/10;
        }
    }
    printf("%I64d\n",ctr);
    return 0;
}