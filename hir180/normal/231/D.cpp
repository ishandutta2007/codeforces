#include <cstdio>
using namespace std;
/* it is one fifty-seven midnight*/
int a[7],x,y,z,x1,y1,z1,i,j,sum=0;
int main(){
scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&x,&y,&z,&x1,&y1,&z1,&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]);
if(x>x1){sum+=a[6];}
if(x<0){sum+=a[5];}
if(z>z1){sum+=a[4];}
if(z<0){sum+=a[3];}
if(y>y1){sum+=a[2];}
if(y<0){sum+=a[1];}
printf("%d\n",sum);
return 0;
}