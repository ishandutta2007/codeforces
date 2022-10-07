#include<stdio.h>
int n,m,dx,dy;
int px[100100];
int py[100100];
int v[1000100];
int tn[1000100];
int ans;
int main(){
	long long int i,j;
	scanf("%d%d%d%d",&n,&m,&dx,&dy);
	for(i=0;i<n;i++){
		v[(dx*i)%n]=(dy*i)%n;
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&px[i],&py[i]);
		tn[(py[i]+n-v[px[i]])%n]++;
	}
	for(i=0;i<n;i++){
		if(tn[i]>tn[ans])ans=i;
	}
	printf("0 %d",ans);
}