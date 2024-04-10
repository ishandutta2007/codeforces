#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long Int;

Int nums1[51],nums2[51];

int main()
{
    Int n,m;
    Int i,j;
    Int maxratio=-1;
    Int ctr=0;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums1[i]);
    }
    
    scanf("%I64d",&m);
    
    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&nums2[i]);
    }
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if ( nums2[j]%nums1[i]==0 )
            {
                if (nums2[j]/nums1[i]>maxratio)
                {
                    maxratio=nums2[j]/nums1[i];
                    ctr=1;
                }
                else if (nums2[j]/nums1[i]==maxratio)
                {
                    ctr++;
                }
            }
        }
    }
    printf("%I64d\n",ctr);
    return 0;
}