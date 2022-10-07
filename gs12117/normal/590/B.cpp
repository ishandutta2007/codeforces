#include<stdio.h>
int xa,ya,xb,yb;
int x,y;
int v,z;
int vx,vy,wx,wy;
int f(double s){
	double px,py;
	px=x;
	py=y;
	if(z<s){
		px-=vx*z;
		py-=vy*z;
		px-=wx*(s-z);
		py-=wy*(s-z);
	}
	else{
		px-=vx*s;
		py-=vy*s;
	}
	if(px*px+py*py<=s*s*v*v){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int i;
	double p,q;
	scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
	x=xb-xa;
	y=yb-ya;
	scanf("%d%d",&v,&z);
	scanf("%d%d",&vx,&vy);
	scanf("%d%d",&wx,&wy);
	p=1e16;
	q=0;
	for(i=0;i<1000;i++){
		if(f(q+p)==0)q+=p;
		p/=2;
	}
	printf("%.20lf",q);
	return 0;
}