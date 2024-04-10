#include<stdio.h>
int n;
int ans[1010];
int ansn;
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		for(j=2;j<i;j++){
			if(i%j==0)break;
		}
		if(j==i){
			j=i;
			while(j<=n){
				ans[ansn]=j;
				ansn++;
				j*=i;
			}
		}
	}
	printf("%d\n",ansn);
	for(i=0;i<ansn;i++){
		printf("%d ",ans[i]);
	}
}