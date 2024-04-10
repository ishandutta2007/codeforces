#include<stdio.h>
int d[50];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%d",d+i);
	if(d[0]==0)printf("0\n");
	else{
		for(int i=0;i<b;i++){
			if(d[i]==0){
				printf("%d\n",i);
				return 0;
			}
		}
		int r=b;
		for(int i=b;i<a;i++)if(d[i]==d[b-1]&&d[i])r++;
		printf("%d\n",r);
	}
}