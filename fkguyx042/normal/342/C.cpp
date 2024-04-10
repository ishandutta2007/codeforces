#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int i,j,p;
int ans;
double r,h;
int main()
{ scanf("%lf%lf",&r,&h);
  if (h*2<r) printf("1\n");else{
  ans=(int)(h/r)*2;
  h=h-(int)(h/r)*r;
  if (h<0.5*r) ans++;
  else if (h<double((double)sqrt(3)/2)*r)
       ans+=2;
 else ans+=3;
printf("%d",ans);}
return 0;
}