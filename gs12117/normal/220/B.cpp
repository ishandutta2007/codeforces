#include<stdio.h>
int n,m;
int a[100100];
int b[100100];
int c[510];
int cocc[510][100100];
int cn;
int qry[100100][2];
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(a[i]>n)a[i]=0;
	}
	for(i=0;i<n;i++){
		b[a[i]]++;
	}
	for(i=1;i<=n;i++){
		if(b[i]>=i){
			c[cn]=i;
			cn++;
		}
	}
	for(i=0;i<cn;i++){
		for(j=0;j<n;j++){
			cocc[i][j+1]=cocc[i][j];
			if(a[j]==c[i])cocc[i][j+1]++;
		}
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&qry[i][0],&qry[i][1]);
		int ans=0;
		for(j=0;j<cn;j++){
			if(cocc[j][qry[i][1]]-cocc[j][qry[i][0]-1]==c[j]){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}