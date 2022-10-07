#include<stdio.h>
#include<algorithm>
int n,m;
struct st{
	int val,dist;
	bool operator<(const st&r)const{
		return dist<r.dist;
	}
}a[400100];
int ansa,ansb;
int tansa,tansb;
int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i].dist);
		a[i].val=1;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&a[n+i].dist);
		a[n+i].val=0;
	}
	std::sort(a,a+n+m);
	tansa=3*n;
	tansb=3*m;
	ansa=tansa;
	ansb=tansb;
	for(i=0;i<n+m;i++){
		while(i<n+m-1&&a[i].dist==a[i+1].dist){
			if(a[i].val){
				tansa--;
			}
			else{
				tansb--;
			}
			i++;
		}
		if(a[i].val){
			tansa--;
		}
		else{
			tansb--;
		}
		if(ansa-ansb<tansa-tansb){
			ansa=tansa;
			ansb=tansb;
		}
	}
	printf("%d:%d",ansa,ansb);
}