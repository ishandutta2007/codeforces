#include<stdio.h>
#include<algorithm>
int n;
double p,q;
struct pj{
	double x,y;
	bool operator<(const pj&r)const{
		return x>r.x||(x==r.x&&y>r.y);
	}
};
pj a[100100];
int chk[100100];
int stk[100100];
int sp;
double ans;
double calc(double ax,double ay,double bx,double by){
	return (by-ay+ax-bx)/(ax*by-ay*bx);
}
int main(){
	int i;
	scanf("%d%lf%lf",&n,&p,&q);
	for(i=0;i<n;i++){
		scanf("%lf%lf",&a[i].x,&a[i].y);
		a[i].x/=p;
		a[i].y/=q;
	}
	p=1;
	q=1;
	std::sort(a,a+n);
	for(i=0;i<n;i++){
		if(a[i].x>a[i].y)chk[i]=1;
		else chk[i]=0;
	}
	stk[0]=0;
	sp=1;
	for(i=1;i<n;i++){
		if(a[i].x>=a[i-1].x)continue;
		while(sp>1&&a[i].y>a[stk[sp-1]].y+((a[i].x-a[stk[sp-1]].x)*(a[stk[sp-1]].y-a[stk[sp-2]].y)/(a[stk[sp-1]].x-a[stk[sp-2]].x))){
			sp--;
		}
		stk[sp]=i;
		sp++;
	}
	ans=-1;
	for(i=0;i<n;i++){
		if(chk[i]==0){
			if(ans<0||ans>1/a[i].x){
				ans=1/a[i].x;
			}
		}
		else{
			if(ans<0||ans>1/a[i].y){
				ans=1/a[i].y;
			}
		}
	}
	for(i=0;i<sp-1;i++){
		if(chk[stk[i]]!=chk[stk[i+1]]){
			if(ans<0||ans>calc(a[stk[i]].x,a[stk[i]].y,a[stk[i+1]].x,a[stk[i+1]].y))ans=calc(a[stk[i]].x,a[stk[i]].y,a[stk[i+1]].x,a[stk[i+1]].y);
		}
	}
	printf("%.20lf",ans);
}