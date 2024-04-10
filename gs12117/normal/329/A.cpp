#include<stdio.h>
int n;
char map[110][110];
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",map[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(map[i][j]=='.')break;
		}
		if(j==n)break;
	}
	if(i==n){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(map[i][j]=='.'){
					printf("%d %d\n",i+1,j+1);
					break;
				}
			}
			if(j==n)break;
		}
	}
	else{
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(map[j][i]=='.')break;
			}
			if(j==n)break;
		}
		if(i==n){
			for(i=0;i<n;i++){
				for(j=0;j<n;j++){
					if(map[j][i]=='.'){
						printf("%d %d\n",j+1,i+1);
						break;
					}
				}
				if(j==n)break;
			}
		}
		else{
			printf("-1");
		}
	}
}