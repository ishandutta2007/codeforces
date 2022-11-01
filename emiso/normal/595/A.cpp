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
    int i,n,m,a,b,co=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d %d",&a,&b);
            if(a||b) co++;
        }
    }
    printf("%d\n",co);
    return 0;
}