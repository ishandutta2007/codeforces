#include<stdio.h>
#include<algorithm>
int n;
double d[110];
double u,v;
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf",&d[i]);
	}
	std::sort(d,d+n);
	u=1;
	v=0;
	for(i=n-1;i>=0;i--){
		if(v<v*(1-d[i])+u*d[i]){
			v=v*(1-d[i])+u*d[i];
			u*=1-d[i];
		}
	}
	printf("%.11lf",v);
}