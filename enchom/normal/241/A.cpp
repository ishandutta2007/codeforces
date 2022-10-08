#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int cost[1001],regen[1001];
Int m,k;
Int fuel,maxregen,timepassed;

int main()
{
    Int i;
    Int town=1;
    
    scanf("%I64d %I64d",&m,&k);
    
    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&cost[i]);
    }
    for (i=1;i<=m;i++)
    {
        scanf("%I64d",&regen[i]);
    }
    
    fuel=regen[1];
    maxregen=regen[1];
    timepassed=0;
    
    while(town<=m)
    {
        if (fuel>=cost[town])
        {
            ///cout<<"going from town "<<town<<" to town "<<town+1<<" and losing "<<cost[town]<<" fuel and time!"<<endl;
            fuel-=cost[town];
            timepassed+=cost[town];
            
            town++;
            fuel+=regen[town];
            
            
            if (regen[town]>maxregen)
            {
                ///cout<<"new magical regeneration point"<<endl;
                maxregen=regen[town];
            }
        }
        else
        {
            ///cout<<"cant go from town "<<town<<" to town "<<town+1<<" cuz i got only "<<fuel<<" fuel and it costs "<<cost[town]<<endl;
            ///cout<<"recovering with "<<maxregen<<" for time "<<k<<endl;
            timepassed+=k;
            fuel+=maxregen;
        }
    }
    printf("%I64d\n",timepassed);
    return 0;
}