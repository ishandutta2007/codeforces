#include<stdio.h>
int n,m;
int edge[100100][2];
int uft[100100][2];
int ans;
int uftf(int x){
	if(x==uft[x][0])return x;
	uftf(uft[x][0]);
	uft[x][1]=uft[uft[x][0]][1]^uft[x][1];
	uft[x][0]=uft[uft[x][0]][0];
	return uft[x][0];
}
int main(){
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
	}
	for(i=1;i<=n;i++){
		uft[i][0]=i;
		uft[i][1]=0;
	}
	for(i=0;i<m;i++){
		if(uftf(edge[i][0])==uftf(edge[i][1])){
			if(uft[edge[i][0]][1]==uft[edge[i][1]][1]){
				printf("-1");
				return 0;
			}
		}
		else{
			uft[uft[edge[i][0]][0]][1]=uft[edge[i][0]][1]^uft[edge[i][1]][1]^1;
			uft[uft[edge[i][0]][0]][0]=uft[edge[i][1]][0];
		}
	}
	ans=0;
	for(i=1;i<=n;i++){
		uftf(i);
		if(uft[i][1]==0)ans++;
	}
	printf("%d\n",ans);
	for(i=1;i<=n;i++){
		if(uft[i][1]==0)printf("%d ",i);
	}
	printf("\n");
	printf("%d\n",n-ans);
	for(i=1;i<=n;i++){
		if(uft[i][1]==1)printf("%d ",i);
	}
	return 0;
}