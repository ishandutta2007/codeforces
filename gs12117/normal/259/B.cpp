#include<stdio.h>
int a[3][3];
int main(){
	int i,j,k;
	k=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			scanf("%d",&a[i][j]);
			k+=a[i][j];
		}
	}
	k/=2;
	for(i=0;i<3;i++){
		if(a[i][0]==0){
			a[i][0]=k-a[i][1]-a[i][2];
		}
		if(a[i][1]==0){
			a[i][1]=k-a[i][0]-a[i][2];
		}
		if(a[i][2]==0){
			a[i][2]=k-a[i][0]-a[i][1];
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}