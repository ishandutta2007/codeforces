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
    int i,n,x[4],y[4];
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d %d",&x[i],&y[i]);
    }
    if(n==1) printf("-1\n");
    else if(n==2) {
        if(x[0] != x[1] && y[0] != y[1]) printf("%d\n",abs((x[0]-x[1])*(y[0]-y[1])));
        else printf("-1\n");
    }
    else if(n==3) {
        if(x[0] != x[1] && y[0] != y[1]) printf("%d\n",abs((x[0]-x[1])*(y[0]-y[1])));
        else if (x[1] != x[2] && y[1] != y[2]) printf("%d\n",abs((x[1]-x[2])*(y[1]-y[2])));
        else printf("%d\n",abs((x[0]-x[2])*(y[0]-y[2])));
    }
    else {
        if(x[0] != x[1] && y[0] != y[1]) printf("%d\n",abs((x[0]-x[1])*(y[0]-y[1])));
        else if (x[0] != x[2] && y[0] != y[2]) printf("%d\n",abs((x[0]-x[2])*(y[0]-y[2])));
        else if (x[0] != x[3] && y[0] != y[3]) printf("%d\n",abs((x[0]-x[3])*(y[0]-y[3])));
        else if (x[1] != x[2] && y[1] != y[2]) printf("%d\n",abs((x[1]-x[2])*(y[1]-y[2])));
        else if (x[1] != x[3] && y[1] != y[3]) printf("%d\n",abs((x[1]-x[3])*(y[1]-y[3])));
        else printf("%d\n",abs((x[2]-x[3])*(y[2]-y[3])));
    }
    return 0;
}