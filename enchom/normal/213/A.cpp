#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long Int;

Int wantcomp[201];
Int needstobedone[201][201];
Int ntbL[201];
bool done[201];
Int n,k;

bool isdone()
{
    Int i;
    for (i=1;i<=n;i++)
    {
        if (!done[i])
        return false;
    }
    return true;
}

int main()
{
    Int i,j;
    Int canbedone[4]={0,0,0,0};
    Int curcomp=0;
    Int hours=0;
    Int minhours=999999999;
    bool cando;
    bool didshit;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&wantcomp[i]);
    }
    
    for (i=0;i<=200;i++)
    {
        ntbL[i]=0;
        done[i]=false;
    }
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&k);
        for (j=1;j<=k;j++)
        {
            ntbL[i]++;
            scanf("%I64d",&needstobedone[i][ ntbL[i] ]);
        }
    }
    for (i=1;i<=n;i++)
    {
        if (ntbL[i]==0)
        {
            canbedone[ wantcomp[i] ]++;
        }
    }
    
    curcomp=3;
    
    ///cout<<"starting at "<<curcomp<<endl;
    
    while( !isdone() )
    {
        didshit=true;
        while(didshit)
        {
            didshit=false;
            for (i=1;i<=n;i++)
            {
                if (done[i] || wantcomp[i]!=curcomp)
                continue;
                
                cando=true;
                for (j=1;j<=ntbL[i];j++)
                {
                    if (!done[needstobedone[i][j]])
                    {
                        cando=false;
                        break;
                    }
                }
                if (cando)
                {
                    ///cout<<i<<" was done perfectly at comp "<<curcomp<<endl;
                    hours++;
                    done[i]=true;
                    didshit=true;
                }
            }
        }
        
        curcomp++;
        hours++;
        if (curcomp==4)
        curcomp=1;
    }
    hours--;
    
    if (minhours>hours)
    minhours=hours;
    
    ////////////////////////////////////////
    
    for (i=1;i<=n;i++)
    {
        done[i]=false;
    }
    curcomp=2;
    hours=0;
    
    ///cout<<"starting at "<<curcomp<<endl;
    
    while( !isdone() )
    {
        didshit=true;
        while(didshit)
        {
            didshit=false;
            for (i=1;i<=n;i++)
            {
                if (done[i] || wantcomp[i]!=curcomp)
                continue;
                
                cando=true;
                for (j=1;j<=ntbL[i];j++)
                {
                    if (!done[needstobedone[i][j]])
                    {
                        cando=false;
                        break;
                    }
                }
                if (cando)
                {
                    ///cout<<i<<" was done perfectly at comp "<<curcomp<<endl;
                    hours++;
                    done[i]=true;
                    didshit=true;
                }
            }
        }
        
        curcomp++;
        hours++;
        if (curcomp==4)
        curcomp=1;
    }
    hours--;
    
    ///cout<<hours<<endl;
    if (minhours>hours)
    minhours=hours;
    
    /////////////////////////////////////
    
    for (i=1;i<=n;i++)
    {
        done[i]=false;
    }
    
    curcomp=1;
    hours=0;
    
    ///cout<<"starting at "<<curcomp<<endl;
    
    while( !isdone() )
    {
        didshit=true;
        while(didshit)
        {
            didshit=false;
            for (i=1;i<=n;i++)
            {
                if (done[i] || wantcomp[i]!=curcomp)
                continue;
                
                cando=true;
                for (j=1;j<=ntbL[i];j++)
                {
                    if (!done[needstobedone[i][j]])
                    {
                        cando=false;
                        break;
                    }
                }
                if (cando)
                {
                    ///cout<<i<<" was done perfectly at comp "<<curcomp<<endl;
                    hours++;
                    done[i]=true;
                    didshit=true;
                }
            }
        }
        
        curcomp++;
        hours++;
        if (curcomp==4)
        curcomp=1;
    }
    hours--;
    
    ///cout<<hours<<endl;
    if (minhours>hours)
    minhours=hours;
    
    printf("%I64d\n",minhours);
    return 0;
}