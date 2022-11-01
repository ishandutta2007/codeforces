#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int main()
{
    int i,n,d1,d2,d3,mi,df1,df2,df3;
    scanf("%d %d %d",&d1,&d2,&d3);
    df3 = min(d3, d1 + d2);
    df2 = min(d2, d1 + d3);
    df1 = min(d1, d2 + d3);
    mi = df1 + df2 + df3;
    printf("%d\n",mi);
    return 0;
}