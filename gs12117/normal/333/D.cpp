#include<stdio.h>
int n,m;
int a[1010][1010];
int b[1010][1010];
int bn[1010];
int c[1010][1010];
bool para(int x){
	int i,j,k;
	for(i=0;i<n;i++){
		bn[i]=0;
		for(j=0;j<m;j++){
			if(a[i][j]>=x){
				b[i][bn[i]]=j;
				bn[i]++;
			}
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			c[i][j]=0;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<bn[i];j++){
			for(k=0;k<j;k++){
				if(c[b[i][j]][b[i][k]]==1)return 1;
				c[b[i][j]][b[i][k]]=1;
			}
		}
	}
	return 0;
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	j=-1;
	for(i=30;i>=0;i--){
		j+=1<<i;
		if(para(j)==0)j-=1<<i;
	}
	printf("%d",j);
}