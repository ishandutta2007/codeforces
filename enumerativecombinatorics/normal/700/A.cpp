#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int main(){
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	double left=0;
	double right=(double)b/d;
	int r=(a+e-1)/e;
	for(int i=0;i<100;i++){
		double M=(left+right)/2;
		double at=0;
		double t=0;
		double x=0;
		for(int j=0;j<r;j++){
			t+=M;
			at+=M*d;
			if(j==r-1)break;
			x=t*c;
			double t2=(at-x)/(c+d);
			x+=t2*c;
			at=x;
			t+=t2;
		}
	//	printf("%f: %f %f\n",M,t,at);
		if(at<b){
			left=M;
		}else right=M;
	}
	//printf("%f\n",left);
	printf("%.12f\n",left+((double)b-left*d)/c);
}