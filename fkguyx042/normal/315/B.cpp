#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
#include<vector>
using namespace std;
#define LL long long
LL a[100050];
int main()
{
   int n,m,i,j,t,v,u;
   while(~scanf("%d%d",&n,&m))
   {
       for(i=1;i<=n;++i)
           scanf("%I64d",&a[i]);
       int y=0; //update
       while(m--)
       {
           scanf("%d%d",&t,&v);
           if(t==1)
            {
                scanf("%d",&u);
                a[v]=u;
                a[v]-=y; //important
           }
           else if(t==2)
           {
               y+=v;
           }
           else 
           {
               printf("%I64d\n",a[v]+y);
           }
       }
   }
   return 0;
}