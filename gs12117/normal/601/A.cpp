#include<stdio.h>
int n,m;
int a[100000][2];
int b[410][410];
int dist[410];
int chk[410];
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
		b[a[i][0]][a[i][1]]=1;
		b[a[i][1]][a[i][0]]=1;
	}
	if(b[1][n]==1){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				b[i][j]=1-b[i][j];
			}
		}
	}
	for(i=2;i<=n;i++){
		dist[i]=99999999;
	}
	dist[1]=0;
	while(1){
		k=-1;
		for(i=1;i<=n;i++){
			if(chk[i]==0&&(k==-1||dist[k]>dist[i])){
				k=i;
			}
		}
		if(k==-1)break;
		chk[k]=1;
		for(i=1;i<=n;i++){
			if(i==k)continue;
			if(b[i][k]==1&&dist[i]>dist[k]+1){
				dist[i]=dist[k]+1;
			}
		}
	}
	if(dist[n]>12345)dist[n]=-1;
	printf("%d",dist[n]);
}