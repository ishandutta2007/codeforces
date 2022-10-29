#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int r,g,b,ans,sum;
int main()
 { scanf("%d%d%d",&r,&g,&b);
     ans+=r/3;
    ans+=g/3;
    ans+=b/3;
      if (r!=0) {
     r-=r/3*3;
     if (r==0) r+=3,ans--; }
    if (g!=0)
     {
     g-=g/3*3;
     if (g==0) g+=3,ans--; }
    if (b!=0)
     {
     b-=b/3*3;
     if (b==0) b+=3,ans--; }
    sum=min(r,min(g,b));
     if (r/3+g/3+b/3>sum) ans+=r/3+g/3+b/3; else ans+=sum;
   printf("%d\n",ans);
}