#include<stdio.h>
int n;
char a[210];
int d[3];
int main(){
	int i,j;
	scanf("%d%s",&n,a);
	for(i=0;i<n;i++){
		if(a[i]=='B')d[0]++;
		if(a[i]=='G')d[1]++;
		if(a[i]=='R')d[2]++;
	}
	if(d[0]==0&&d[1]==0){
		printf("R");
		return 0;
	}
	if(d[0]==0&&d[2]==0){
		printf("G");
		return 0;
	}
	if(d[1]==0&&d[2]==0){
		printf("B");
		return 0;
	}
	if(n==2){
		if(d[0]==0)printf("B");
		if(d[1]==0)printf("G");
		if(d[2]==0)printf("R");
		return 0;
	}
	if(d[0]+d[1]==1){
		printf("BG");
		return 0;
	}
	if(d[0]+d[2]==1){
		printf("BR");
		return 0;
	}
	if(d[1]+d[2]==1){
		printf("GR");
		return 0;
	}
	printf("BGR");
	return 0;
}