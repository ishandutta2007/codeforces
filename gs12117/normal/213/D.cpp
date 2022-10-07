#include<stdio.h>
#include<math.h>
int n;
double loc[510][2];
double sf,gr;
double ans[510];
int main(){
	int i;
	sf=sqrt(5.0);
	gr=(sf+1)/2;
	scanf("%d",&n);
	loc[0][0]=0;
	loc[0][1]=0;
	for(i=0;i<n;i++){
		loc[i*4+1][0]=gr*5*(i*2+1);
		loc[i*4+2][0]=gr*5*(i*2+1)+5;
		loc[i*4+3][0]=gr*5*(i*2+1)-5;
		loc[i*4+4][0]=gr*10*(i+1);
		loc[i*4+1][1]=sqrt((gr*gr*4)-1)/gr/gr*5;
		loc[i*4+2][1]=-(sqrt((gr*gr*4)-1)/gr*5);
		loc[i*4+3][1]=-(sqrt((gr*gr*4)-1)/gr*5);
		loc[i*4+4][1]=0;
	}
	printf("%d\n",4*n+1);
	for(i=0;i<=4*n;i++){
		printf("%.30lf %.30lf\n",loc[i][0],loc[i][1]);
	}
	for(i=0;i<n;i++){
		printf("%d %d %d %d %d\n",4*i+1,4*i+2,4*i+5,4*i+3,4*i+4);
	}
	for(i=0;i<n;i++){
		printf("%d %d %d %d ",4*i+1,4*i+3,4*i+2,4*i+4);
	}
	for(i=n;i>=0;i--){
		printf("%d ",4*i+1);
	}
}