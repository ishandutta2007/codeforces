#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int i,j,p,n,m,st,ed;
struct node{int t;int left;int right;}f[1000001];
int ans,now;
int main()
{ scanf("%d%d%d%d",&n,&m,&st,&ed);
   for (i=1;i<=m;i++)
     scanf("%d%d%d",&f[i].t,&f[i].left,&f[i].right);
     now=0;
if (st==ed) printf("0\n");
else {
f[m+1].t=2147483647;
 for (i=1;i<=m+1;i++)
  {
   for (j=f[i-1].t+1;j<=f[i].t-1;j++)
     { now++;
         if (st>ed) {printf("L"); st-=1;if (st==ed) return 0;} 
         else {st+=1; printf("R");if (st==ed) { return 0;}}
         }
    if (st>ed){ if ((f[i].left>st||f[i].right<st)&&(f[i].left>st-1||f[i].right<st-1)) {st-=1;printf("L"); if (st==ed) return 0;}
                  else printf("X");
                  }
        else {    if ((f[i].left>st||f[i].right<st)&&((f[i].left>st+1)||(f[i].right<st+1))) {st+=1;printf("R"); if (st==ed){ return 0;}}
                  else printf("X"); 
                  }    
}      
}  
return 0;
}