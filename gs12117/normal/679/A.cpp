#include<stdio.h>
int n=100;
char tmp[10];
int main(){
	int i,j,k;
	k=1;
	for(i=2;k*i<=n;i++){
		if(k==1&&i*i>n)break;
		for(j=2;j<i;j++){
			if(i%j==0)break;
		}
		if(i==j){
			printf("%d\n",i);
			fflush(stdout);
			scanf("%s",tmp);
			if(tmp[0]=='y'){
				if(k!=1){
					puts("composite");
					return 0;
				}
				k=i;
				if(i*i<=n){
					printf("%d\n",i*i);
					fflush(stdout);
					scanf("%s",tmp);
					if(tmp[0]=='y'){
						puts("composite");
						return 0;
					}
				}
			}
		}
	}
	puts("prime");
	return 0;
}