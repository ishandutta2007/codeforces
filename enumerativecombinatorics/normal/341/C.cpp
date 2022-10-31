#include<stdio.h>
long long C[3000][3000];
int c[2000];
int d[2000];
int main(){
	int a;
	scanf("%d",&a);
	int n=0;
	int m=0;
	for(int i=0;i<a;i++){
		scanf("%d",c+i);
		if(~c[i]){
			d[c[i]-1]=1;
		}else n++;
	}
	for(int i=0;i<a;i++){
		if(!d[i]&&c[i]==-1){
			m++;
		}
	}
	long long ret=0;
	int mod=1000000007;
	C[0][0]=1LL;
	for(int i=0;i<2001;i++)
		for(int j=0;j<=i;j++){
			C[i+1][j]=(C[i+1][j]+C[i][j])%mod;
			C[i+1][j+1]=(C[i+1][j+1]+C[i][j])%mod;
		}
	for(int i=0;i<=m;i++){
		long long val=C[m][i];
		for(int j=0;j<n-i;j++){
			val=val*(n-i-j)%mod;
		}
		if(i%2)ret=(ret+mod-val)%mod;
		else ret=(ret+val)%mod;
	}
	printf("%d\n",(int)ret);
}