#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

bool done[2001];
Int n,m,k;
Int total=1;

void Do(Int a)
{
    done[a]=true;
    Int i;
    Int ind,twin,rtwin;
    
    for (i=1;i<=n-k+1;i++)
    {
        if (a>=i && a<=i+k-1)
        {
            ind=a-i+1;
            twin=k-ind+1;
            rtwin=i+twin-1;
            
            if (!done[rtwin])
            {
                Do(rtwin);
            }
        }
    }
    return;
}

int main()
{
    Int i;
    
    scanf("%I64d %I64d %I64d",&n,&m,&k);
    
    for (i=0;i<=2000;i++)
    done[i]=false;
    
    for (i=1;i<=n;i++)
    {
        if (!done[i])
        {
            total=(total*m)%1000000007;
            
            Do(i);
        }
    }
    printf("%I64d\n",total);
    return 0;
}