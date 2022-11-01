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
    int i,n,di,d=0,h[105],dt = 9999999;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&h[i]);
    for(int i=1;i<n-1;i++) {
            int d = h[i+1] - h[i-1];
            for(int j=0;j<n-1;j++) {
                    int di = h[j+1] - h[j];
                    d = max(di,d);
            }
            dt = min(dt,d);
    }
    printf("%d\n",dt);
    return 0;
}