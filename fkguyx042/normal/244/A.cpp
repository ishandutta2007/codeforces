#include <iostream>
 #include <cstdio>
 #include <map>
 #include <algorithm>
 #include <cstring>
 #include <cmath>
 using namespace std;
 #define N 1000000
 int p[100],o[1000];
 int main()
 {
     int n,k,i,j,u;
     scanf("%d%d",&n,&k);
    for(i = 1;i <= k;i ++)
    {
         scanf("%d",&p[i]);
         o[p[i]] = 1;
     }
     for(i = 1;i <= k;i ++)
    {
         printf("%d",p[i]);
        for(j = 2;j <= n;j ++)
        {
            for(u = 1;u <= n*k;u ++)
             {
                 if(!o[u])
                 {
                    o[u] = 1;
                    printf(" %d",u);
                     break;
                }
            }
         }
        printf("\n");
     }
     return 0;
 }