#include<stdio.h>
int n,m;
char a[5010][5010];
int nz[5010];
int nzn[5010];
int ans;
int main(){
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",&a[i]);
	}
	for(j=0;j<n;j++){
		for(k=0;a[j][k]=='1';k++);
		nz[j]=k;
		nzn[k]++;
	}
	for(i=0;i<m;i++){
		k=0;
		for(j=m;j>=i;j--){
			k+=nzn[j];
			if(ans<(j-i)*k)ans=(j-i)*k;
		}
		for(j=0;j<n;j++){
			if(nz[j]==i){
				for(k=i+1;a[j][k]=='1';k++);
				nz[j]=k;
				nzn[k]++;
			}
		}
	}
	printf("%d",ans);
}