#include<stdio.h>
int n;
int a[100100];
int num[10];
int bnum[10];
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		num[a[i]]++;
	}
	if(num[7]!=0||num[5]!=0){
		printf("-1");
		return 0;
	}
	if(num[4]){
		bnum[0]+=num[4];
		num[2]-=num[4];
		num[1]-=num[4];
	}
	if(num[2]){
		bnum[1]+=num[2];
		num[6]-=num[2];
		num[1]-=num[2];
	}
	if(num[3]){
		bnum[2]+=num[3];
		num[6]-=num[3];
		num[1]-=num[3];
	}
	if(num[6]!=0||num[1]!=0||bnum[0]<0||bnum[1]<0||bnum[2]<0){
		printf("-1");
		return 0;
	}
	for(i=0;i<bnum[0];i++){
		printf("1 2 4\n");
	}
	for(i=0;i<bnum[1];i++){
		printf("1 2 6\n");
	}
	for(i=0;i<bnum[2];i++){
		printf("1 3 6\n");
	}
}