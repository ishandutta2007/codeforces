#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int graph[101][101];

int main()
{
    Int i,j;
    Int k;
    Int n;
    
    scanf("%I64d",&k);
    
    for (i=0;i<=100;i++)
    {
        for (j=0;j<=100;j++)
        {
            graph[i][j]=0;
        }
    }
    graph[1][2]=1;
    graph[2][1]=1;
    graph[1][3]=1;
    graph[3][1]=1;
    graph[2][3]=1;
    graph[3][2]=1;
    k--;
    if (k==0)
    {
        printf("3\n011\n101\n110\n");
        return 0;
    }
    for (i=4;i<=100;i++)
    {
        graph[1][i]=1;
        graph[i][1]=1;
        n=i;
        
        for (j=2;j<=i-1;j++)
        {
            if (k>=j-1)
            {
                k=k-(j-1);
                graph[i][j]=1;
                graph[j][i]=1;
            }
            else
            {
                break;
            }
        }
        if (k==0)
        break;
    }
    
    printf("%I64d\n",n);
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            printf("%I64d",graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}