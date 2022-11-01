#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>

#define w1 while(1)
#define sint(n) scanf("%d",&n)
#define pint(n) printf("%d\n",n)
#define For(n) for(i=1;i<=n;i++)
#define For0(n) for(i=0;i<n;i++)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int main()
{
    int i,n,ii[4],m[5005],j;
    scanf("%d",&n);
    fill(ii,0);
    for(i=1;i<=n;i++)
    {
                 scanf("%d",&m[i]);  
                 ii[m[i]]++; 
    }
    int t = min(ii[1],min(ii[2],ii[3]));
    printf("%d\n",t);
    
    for(i=0;i<t;i++)
    {
                    int i1=0,i2=0,i3=0;
                    for(j=1;j<=n;j++)
                    {
                                     if(m[j]==1)
                                     {
                                                m[j]=0;
                                                i1=j;
                                                j=n;
                                     }
                    }
                    for(j=1;j<=n;j++)
                    {
                                     if(m[j]==2)
                                     {
                                                m[j]=0;
                                                i2=j;
                                                j=n;
                                     }
                    }
                    for(j=1;j<=n;j++)
                    {
                                     if(m[j]==3)
                                     {
                                                m[j]=0;
                                                i3=j;
                                                j=n;
                                     }
                    }
                    printf("%d %d %d\n",i1,i2,i3);
    }
    return 0;
}