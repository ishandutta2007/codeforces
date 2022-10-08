#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long Int;

Int nums[9][9];

int main()
{
    Int n,k;
    Int i,j;
    Int perms[9]={0,1,2,3,4,5,6,7,8};
    Int gennum;
    Int maxnum=-1,minnum=999999999;
    Int mindif=999999999;
    char ch;
    
    scanf("%I64d %I64d",&n,&k);
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=k;j++)
        {
            cin>>ch;
            nums[i][j]=(int)(ch-'0');
        }
    }
    
    do
    {
        maxnum=-1;
        minnum=999999999;
        for (i=1;i<=n;i++)
        {
            gennum=0;
            
            for (j=1;j<=k;j++)
            {
                gennum=gennum*10+nums[i][ perms[j] ];
            }
            if (gennum>maxnum)
            maxnum=gennum;
            if (gennum<minnum)
            minnum=gennum;
        }
        if (maxnum-minnum<mindif)
        {
            mindif=maxnum-minnum;
        }
    }while ( next_permutation(perms+1,perms+1+k) );
    printf("%I64d\n",mindif);
    return 0;
}