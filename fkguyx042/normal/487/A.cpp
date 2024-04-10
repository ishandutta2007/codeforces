#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,A,B,C,HA,HB,HC;
int ans=(int)1e9,h,a,d;
bool check(int x,int y,int z)
{ 
    if (y>HC&&z>=HB) return true;
    if (y<=HC&&z<HB) return false;
    if (y<=HC&&z>=HB) return false;
    return (HA+(y-HC)-1)/(y-HC)<(x+(HB-z)-1)/(HB-z);
}
int main()
{
	  scanf("%d%d%d",&A,&B,&C);
	  scanf("%d%d%d",&HA,&HB,&HC);
	  scanf("%d%d%d",&h,&a,&d);
	  for (i=0;;i++)
	  {
	  	   if (i*h>=ans) break;
	  	   for (j=0;j+B<=200;j++)
	  	{
	  		   if (i*h+j*a>=ans) break;
	  		   for (k=0;k+C<=200;k++)
	  		   {
	  		   	  if (i*h+j*a+k*d>=ans) break;
	  		   	  if (i*h+j*a+k*d==5478) 
	  		   	     i=i;
	  		   	  if (check(i+A,j+B,k+C)) ans=i*h+j*a+k*d;
	  		   }
	  	}
}
printf("%d\n",ans);
}