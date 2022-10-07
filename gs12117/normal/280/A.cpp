#include<stdio.h>
#include<math.h>
const double PI=3.1415926535897932;
double n,m,r;
double theta;
int main(){
	int t;
	double ans;
	scanf("%lf%lf%lf",&n,&m,&r);
	if(n<m){
		t=n;
		n=m;
		m=t;
	}
	if(r>90){
		r=180-r;
	}
	if(r==0){
		ans=n*m;
	}
	else if(r==90){
		ans=m*m;
	}
	else{
		theta=PI/180*r;
		if(sin(theta/2)*sqrt((double)n*n+m*m)>m){
			ans=m*m/sin(theta);
		}
		else{
			double tx,ty,dx,dy;
			tx=n/cos(theta/2);
			ty=m/cos(theta/2);
			ans=0.5*ty*(tx/tan(theta/2)-ty)/(1/tan(theta/2)-tan(theta/2));
			ans+=0.5*tx*(ty/tan(theta/2)-tx)/(1/tan(theta/2)-tan(theta/2));
		}
	}
	printf("%.30lf",ans);
}