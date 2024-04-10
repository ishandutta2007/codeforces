#include<stdio.h>
int n,m;
int a[110][110];
int b[110];
int main(){
	int i,j,p;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		p=1;
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]>a[i][p]){
				p=j;
			}
		}
		b[p]++;
	}
	p=1;
	for(i=1;i<=n;i++){
		if(b[i]>b[p])p=i;
	}
	printf("%d",p);
}