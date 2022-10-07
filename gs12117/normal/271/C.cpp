#include<stdio.h>
int n,m;
int main(){
	int i;
	scanf("%d%d",&n,&m);
	if(n<3*m||m==1){
		printf("-1");
		return 0;
	}
	for(i=0;i<m;i++){
		printf("%d %d ",i+1,i+1);
	}
	for(i=0;i<m;i++){
		printf("%d ",i+1);
	}
	for(i=3*m;i<n;i++){
		printf("%d ",m);
	}
}