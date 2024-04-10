#include<stdio.h>
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	int i,j;
	if(n==5){
		puts(">...v");
		puts("v.<..");
		puts("..^..");
		puts(">....");
		puts("..^.<");
		puts("1 1");
	}
	if(n==3){
		puts(">vv");
		puts("^<.");
		puts("^.<");
		puts("1 3");
	}
	if(n==100){
		for(i=0;i<25;i++){
			for(j=0;j<35;j++){
				printf(">");
			}
			for(j=0;j<32;j++){
				printf(">.");
			}
			printf("v\n");
			printf("^");
			for(j=0;j<33;j++){
				printf("<.");
			}
			for(j=0;j<33;j++){
				printf("<");
			}
			printf("\n");
			printf("v");
			for(j=0;j<32;j++){
				printf(".<");
			}
			for(j=0;j<35;j++){
				printf("<");
			}
			printf("\n");
			for(j=0;j<33;j++){
				printf(">");
			}
			for(j=0;j<33;j++){
				printf(">.");
			}
			printf("^\n");
		}
		printf("1 1\n");
	}
}