#include<stdio.h>
char board[9][9];
int main(){
	int i,j;
	for(i=0;i<8;i++){
		scanf("%s",board[i]);
		for(j=0;j<8;j++){
			if((board[i][j]==board[i][0]&&j%2==1)||(board[i][j]!=board[i][0]&&j%2==0)){
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
	return 0;
}