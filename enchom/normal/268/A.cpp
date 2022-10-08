#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct team
{
    Int host,guest;
};

team uniforms[31];

int main()
{
    Int n;
    Int i;
    Int ctr=0;
    Int j;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&uniforms[i].host,&uniforms[i].guest);
    }
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (i==j)
            continue;
            
            if (uniforms[i].host==uniforms[j].guest)
            ctr++;
        }
    }
    printf("%I64d\n",ctr);
    return 0;
}