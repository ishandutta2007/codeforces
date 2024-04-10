#include <stdio.h>
#include <math.h>
double a,b,c;
double a1,b1,c1;
int main(){
scanf("%lf%lf%lf",&a,&b,&c);

double i;
for(i=1;i<=10000;i++){
	double c2 = c/i;
	
	double a2 = a/i;

	if(c2*a2==b){
     a1=a2;
	 b1=i;
	 c1=c2;
	 break;
	}
	
}
int abc=a1+b1+c1;
printf("%d\n",abc*4);
scanf("%lf",&a);
return 0;
}