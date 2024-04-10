#include<stdio.h>
int n,m;
int main(){
	int i;
	scanf("%d%d",&n,&m);
	if(m==3){
		if(n==3){
			printf("0 0\n3 0\n0 3\n");
		}
		else if(n==4){
			printf("0 0\n3 0\n0 3\n1 1\n");
		}
		else{
			printf("-1");
		}
		return 0;
	}
	for(i=1;i<=m;i++){
		printf("%d %d\n",i,i*i);
	}
	for(i=1;i<=n-m;i++){
		printf("%d %d\n",i,-i*i-500*m*m);
	}
}