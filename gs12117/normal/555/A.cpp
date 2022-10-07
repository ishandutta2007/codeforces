#include<stdio.h>
int n,m;
int an[100100];
int ap[100100];
int pc;
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d",&an[i]);
		for(j=0;j<an[i];j++){
			scanf("%d",&ap[j]);
		}
		if(ap[0]==1){
			for(j=0;j<an[i];j++){
				if(ap[j]!=j+1)break;
			}
			pc=j;
		}
	}
	printf("%d",2*(n-pc+1)-m-1);
}