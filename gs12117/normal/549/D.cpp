#include<stdio.h>
int n,m;
char a[106][106];
int b[106][106];
int ans;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",a[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(a[i][j]=='W')b[i][j]=1;
			else b[i][j]=-1;
		}
	}
	ans=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(b[i][j]+b[i+1][j+1]!=b[i][j+1]+b[i+1][j])ans++;
		}
	}
	printf("%d",ans);
}