#include<stdio.h>
int n;
char a[110];
int main(){
	int i,j,k;
	scanf("%d%s",&n,a);
	for(i=0;i<n;i++){
		for(j=1;j<n;j++){
			for(k=0;k<5;k++){
				if(i+j*k<n&&a[i+j*k]=='*')continue;
				else break;
			}
			if(k==5){
				printf("yes");
				return 0;
			}
		}
	}
				printf("no");
				return 0;
}