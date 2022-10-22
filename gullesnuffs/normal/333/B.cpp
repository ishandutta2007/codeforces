#include <stdio.h>
#include <algorithm>

using namespace std;

bool allowed[2][1005];

int main()
{
   int n, m;
   scanf("%d%d", &n, &m);
   for(int i=0; i < 2; ++i)
        for(int j=0; j < n; ++j)
                allowed[i][j]=1;
   if(n <= 2){
       printf("0");
       return 0;
   }
   for(int i=0; i < m; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        allowed[0][a]=0;
        allowed[1][b]=0;
   }
   int ans=0;
   for(int i=0; i < 2; ++i)
       for(int j=1; j < n-1; ++j)
           ans += allowed[i][j];
   if(n%2 && allowed[0][n/2] && allowed[1][n/2])
       --ans;
   printf("%d", ans);
    return 0;
}