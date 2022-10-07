#include<stdio.h>
int n;
int a[3000][2];
int b[3000][2];
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n*n;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
		if(b[a[i][0]][0]==0&&b[a[i][1]][1]==0){
			printf("%d ",i);
			b[a[i][0]][0]=1;
			b[a[i][1]][1]=1;
		}
	}
}