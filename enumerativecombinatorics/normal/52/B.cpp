#include<stdio.h>
char str[1024][1024];
int R[1024];
int C[1024];
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%s",str[i]);
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if(str[i][j]=='*'){
				R[i]++;C[j]++;
			}
		}
	}
	long long ret=0;
	for(int i=0;i<a;i++)
		for(int j=0;j<b;j++)
			if(str[i][j]=='*')ret+=(R[i]-1)*(C[j]-1);
	printf("%I64d\n",ret);
}