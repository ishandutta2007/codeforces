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

using namespace std;

int main()
{
    int i,n,actual=1,flag=0,go,a;
    scanf("%d %d",&n,&go);
    if(go == 1) flag = 1;
    for(i=1;i<n;i++) {
         scanf("%d",&a);
         if(actual == i) {
              actual += a;
         }
         if(actual == go) flag = 1;
    }
    if(flag == 1) printf("YES\n");
    else printf("NO\n");
    return 0;
}