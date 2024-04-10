#include<stdio.h>
int n,m;
int a[510];
int b[250100][2];
double ans;
int main(){
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i+1]);
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
		if(ans<((double)a[b[i][0]]+a[b[i][1]])/b[i][2])ans=((double)a[b[i][0]]+a[b[i][1]])/b[i][2];
	}
	printf("%.30lf",ans);
}