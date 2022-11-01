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
    int i,n,x,actual=1,count=0,l,r;
    scanf("%d %d",&n,&x);
    for(i=0;i<n;i++){
          scanf("%d %d",&l,&r);
          while(l - actual >= x) {
                  actual += x;
          }
          count += r + 1 - actual;
          actual = r + 1;
    }
    printf("%d\n",count);
    return 0;
}