#include<stdio.h>
int n,m;
int rchk[1010];
int cchk[1010];
int ans;
int main(){
	int i,ta,tb;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&ta,&tb);
		rchk[ta-1]=1;
		cchk[tb-1]=1;
	}
	for(i=1;i<n-1;i++){
		ans+=1-rchk[i];
		ans+=1-cchk[i];
	}
	if(n%2==1&&rchk[n/2]==0&&cchk[n/2]==0){
		ans--;
	}
	printf("%d",ans);
}