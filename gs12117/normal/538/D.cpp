#include<stdio.h>
int n;
char a[60][60];
char b[60][60];
char ans[120][120];
int main(){
	int i,j,k,l;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(i=0;i<2*n-1;i++){
		for(j=0;j<2*n-1;j++){
			ans[i][j]='x';
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]!='o')continue;
			for(k=0;k<n;k++){
				for(l=0;l<n;l++){
					if(a[k][l]!='.')continue;
					ans[n-1+k-i][n-1+l-j]='.';
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			b[i][j]='.';
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]=='o'){
				for(k=0;k<n;k++){
					for(l=0;l<n;l++){
						if(ans[n-1+k-i][n-1+l-j]=='x'){
							b[k][l]='x';
						}
					}
				}
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(b[i][j]=='.'&&a[i][j]=='x'){
				printf("NO");
				return 0;
			}
		}
	}
	ans[n-1][n-1]='o';
	printf("YES\n");
	for(i=0;i<2*n-1;i++){
		printf("%s\n",ans[i]);
	}
}