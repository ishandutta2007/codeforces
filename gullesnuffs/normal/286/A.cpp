#include <stdio.h>
#include <algorithm>

int n;
int p[100005];

int main()
{
    using namespace std;
   scanf("%d", &n);
   if(n%4 >= 2)
       printf("-1");
   else{
        for(int i=1; i < n/2; i += 2){
            p[i]=i+1;
            p[i+1]=n-i+1;
            p[n-i+1]=n-i;
            p[n-i]=i;
        }
        if(n%2)
            p[1+n/2]=1+n/2;
        for(int i=1; i <= n; ++i)
            printf("%d ", p[i]);
   }
   /*for(int i=1; i <= n; ++i)
       p[i]=i;
   bool done=0;
   do{
       bool ok=1;
       for(int i=1; i <= n; ++i)
           if(p[p[i]] != n-i+1)
               ok=0;
       if(ok){
           done=1;
           break;
       }
   }
   while(next_permutation(p+1, p+n+1));
   if(done)
       done=1;*/
    return 0;
}