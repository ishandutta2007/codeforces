#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
main(){
    float r,x,y,x2,y2;
    scanf("%f %f %f %f %f",&r,&x,&y,&x2,&y2);
    float d;
    d=sqrt((x2-x)*(x2-x)+(y2-y)*(y2-y));
    int i;
    for(i=0;d>0;d-=2*r,i++);
    printf("%d\n",i);
    return 0;
}