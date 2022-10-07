#include<stdio.h>
#include<algorithm>
int n;
int x[1001000];
int y[1001000];
struct pnt{
	int ord,loc;
	bool operator<(const pnt&r)const{
		return ord<r.ord;
	}
};
pnt p[1001000];
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);
		p[i].loc=i+1;
		p[i].ord=(x[i]/1000)*1001000;
		if((x[i]/1000)%2==0){
			p[i].ord+=y[i];
		}
		else{
			p[i].ord+=1000100-y[i];
		}
	}
	std::sort(p,p+n);
	for(i=0;i<n;i++){
		printf("%d ",p[i].loc);
	}
}