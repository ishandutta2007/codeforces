#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
double A[110000];
double B[110000];

double x[110000];
double y[110000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%lf",A+i);
	for(int i=0;i<a;i++)scanf("%lf",B+i);
	double p1=0;
	double p2=0;
	for(int i=0;i<a;i++)p2+=B[i];
	for(int i=0;i<a-1;i++){
		p1+=A[i];
		p2-=B[i];
		y[i]=0.5*((p1-p2+1)+sqrt(max(0.0,(p1-p2+1)*(p1-p2+1)-4.0*p1)));
		x[i]=0.5*((p1-p2+1)-sqrt(max(0.0,(p1-p2+1)*(p1-p2+1)-4.0*p1)));
	}
	x[a-1]=y[a-1]=1;
	for(int i=a-1;i>0;i--){
		x[i]-=x[i-1];
		y[i]-=y[i-1];
	}
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%.12f",x[i]);
	}
	printf("\n");
	for(int i=0;i<a;i++){
		if(i)printf(" ");
		printf("%.12f",y[i]);
	}
	printf("\n");
	
}