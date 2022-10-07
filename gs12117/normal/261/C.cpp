#include<stdio.h>
long long int n,m;
long long int p;
long long int ans;
long long int cmb[50][50];
int main(){
	long long int i,j;
	cmb[0][0]=1;
	for(i=0;i<46;i++){
		for(j=0;j<=i;j++){
			cmb[i+1][j+1]+=cmb[i][j];
			cmb[i+1][j]+=cmb[i][j];
		}
	}
	scanf("%I64d%I64d",&n,&m);
	p=1;
	while(1){
		if(m%2==1)break;
		p++;
		m=m/2;
	}
	if(m!=1){
		printf("0");
		return 0;
	}
	if(p==1)ans=-1;
	n+=2;
	while(1){
		if(n==0||p<0)break;
		j=1;
		for(i=0;j<=n;i++){
			j*=2;
		}
		j/=2;
		i--;
		ans+=cmb[i][p];
		n-=j;
		p--;
	}
	printf("%I64d",ans);
}