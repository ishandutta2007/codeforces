#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long Int;

int main()
{
    Int n,m;
    Int totalcost=0;
    Int i;
    Int t,T,cost,x;
    Int p;
    Int buses;
    Int left;
    Int willcost;
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d %I64d %I64d",&t,&T,&x,&cost);
        p=T-t;
        
        if (p<=0)
        {
            totalcost=totalcost+(cost+m*x);
        }
        else
        {
            if (p*x<=cost)
            {
               buses=m/p;
               left=m%p;
               willcost=buses*cost;
               if (left>0)
               {
                   willcost=willcost+cost;
               }
               
               if (willcost<cost+m*x)
               totalcost=totalcost+willcost;
               else
               totalcost=totalcost+(cost+m*x);
            }
            else
            {
                buses=m/p;
                left=m%p;
                totalcost=totalcost+buses*cost;
                
                if ( left>0 )
                {
                    totalcost=totalcost+cost;
                }
            }
        }
    }
    printf("%I64d\n",totalcost);
    return 0;
}