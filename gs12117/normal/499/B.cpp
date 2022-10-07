#include<stdio.h>
#include<string.h>
int n,m;
char a[3010][2][15];
char b[3010][15];
int c[3010];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%s%s",a[i][0],a[i][1]);
		if(strlen(a[i][1])<strlen(a[i][0]))c[i]=1;
		else c[i]=0;
	}
	for(i=0;i<n;i++){
		scanf("%s",b[i]);
		for(j=0;j<m;j++){
			if(strcmp(b[i],a[j][0])==0||strcmp(b[i],a[j][1])==0){
				printf("%s ",a[j][c[j]]);
				break;
			}
		}
	}
}