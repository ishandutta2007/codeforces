#include<stdio.h>
char str[2][200][200];
int main(){
	int a;
	scanf("%d",&a);
	if(a%2){
		printf("-1\n");return 0;
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if((i/2+j/2)%2){
				str[0][i][j]='b';
				str[1][i][j]='w';
			}else{
				str[0][i][j]='w';
				str[1][i][j]='b';
			}
		}
	}
	for(int i=0;i<a;i++){
		if(i)printf("\n");
		for(int j=0;j<a;j++)printf("%s\n",str[i%2][j]);
	}
}