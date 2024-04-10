#include<stdio.h>
int n,m;
int a[1010][1010];
long long int csum;
long long int xsum;
long long int ysum;
long long int ans;
long long int xloc,yloc;
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			csum+=a[i][j];
			xsum+=a[i][j]*i;
			ysum+=a[i][j]*j;
		}
	}
	if(csum==0){
		xloc=0;
		yloc=0;
	}
	else{
		xloc=xsum/csum+1;
		if(xsum%csum==0)xloc--;
		yloc=ysum/csum+1;
		if(ysum%csum==0)yloc--;
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			ans+=a[i][j]*(2*i+1-xloc*2)*(2*i+1-xloc*2)*4;
			ans+=a[i][j]*(2*j+1-yloc*2)*(2*j+1-yloc*2)*4;
		}
	}
	printf("%I64d\n",ans);
	printf("%I64d %I64d",xloc,yloc);
}